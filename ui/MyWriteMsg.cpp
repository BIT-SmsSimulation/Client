/**
 * Implementation of MyWriteMsg.
 * 
 * Copyright (c) 2014 BIT-SmsSimulation.
 * 
 * This file is part of BIT-SmsSimulation.
 * 
 * BIT-SmsSimulation is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * BIT-SmsSimulation is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with BIT-SmsSimulation.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MyWriteMsg.h"
#include "MyChooseContacts.h"
#include "MySetTime.h"
#include "../Exception.h"
#include "../service/MessageService.h"

USING_NS_SMS;

MyWriteMsg::MyWriteMsg(ConnectionService * server, QWidget * parent)
	: QDialog(parent), self(new Ui::WriteMsg), server(server)
{
	self->setupUi(this);
}

// msgInfo format: "${receiverNum}${endOfMsg}${content}"
MyWriteMsg::MyWriteMsg(ConnectionService * server, QWidget * parent, QString msgInfo)
	: MyWriteMsg(server, parent)
{
	QStringList strList = msgInfo.split(ConnectionService::endOfMsg);
	if (!strList[0].isEmpty())
	{
		self->lineEdit->setText(strList[0] + utf8(";"));
	}
	self->plainTextEdit->setPlainText(strList[1]);
}

MyWriteMsg::~MyWriteMsg()
{
	delete self;
}

void MyWriteMsg::chooseContacts()
{
	try
	{
		MyChooseContact * chooseContactsWindow = new MyChooseContact(this);
		if (chooseContactsWindow->exec() != QDialog::Accepted)
		{
			chooseContactsWindow->deleteLater();
			return;
		}
		chooseContactsWindow->deleteLater();

		QStringList strList = chooseContactsWindow->getChosenContacts();
		QString currentContacts = self->lineEdit->text();
		if (currentContacts.length() > 0
			&& currentContacts[currentContacts.length() - 1] != utf8(";")[0])
		{
			currentContacts += utf8(";");
		}

		for (int i = 0; i < strList.length(); ++i)
		{
			currentContacts += strList[i] + utf8(";");
		}
		self->lineEdit->setText(currentContacts);
	}
	CATCH_BLOCKS
}

void MyWriteMsg::sendMsg()
{
	try
	{
		checkInput();

		QList<Message> & msgs = getMsgs();

		server->sendMessages(msgs);

		MessageService * msgServer = new MessageService;
		for (int i = 0; i < msgs.length(); ++i)
		{
			msgs[i].setSenderNum(server->getPhoneNum());
			msgs[i].setTime(QDateTime::currentDateTime());
			msgs[i].setType(Message::SENT);
			msgServer->saveMsg(msgs[i]);
		}
		delete msgServer;

		msgs.clear();
		delete &msgs;
		this->accept();
	}
	CATCH_BLOCKS
}

void MyWriteMsg::sendTimedMsg()
{
	try
	{
		checkInput();

		MySetTime * setTime = new MySetTime(this);
		if (setTime->exec() != QDialog::Accepted)
		{
			setTime->deleteLater();
			return;
		}
		setTime->deleteLater();
	
		QDateTime chosenTime = setTime->getTime();

		QList<Message> & msgs = getMsgs();
		MessageService * msgServer = new MessageService;
		for (int i = 0; i < msgs.length(); ++i)
		{
			msgs[i].setSenderNum(server->getPhoneNum());
			msgs[i].setTime(chosenTime);
			msgs[i].setType(Message::TIMED);
			msgServer->saveMsg(msgs[i]);
		}
		delete msgServer;

		msgs.clear();
		delete &msgs;
		this->accept();
	}
	CATCH_BLOCKS
}

void MyWriteMsg::reject()
{
	try
	{
		if (self->plainTextEdit->toPlainText().trimmed().isEmpty())
		{
			QDialog::reject();
			return;
		}

		if (QUESTION(utf8("提醒"), utf8("是否存为草稿？")) == QMessageBox::No)
		{
			QDialog::reject();
			return;
		}

		Message msg;
		msg.setContent(self->plainTextEdit->toPlainText());
		msg.setTime(QDateTime::currentDateTime());
		msg.setType(Message::DRAFT);

		MessageService * msgServer = new MessageService;
		msgServer->saveMsg(msg);
		delete msgServer;

		QDialog::reject();
	}
	CATCH_BLOCKS
}

void MyWriteMsg::checkInput(bool multiReceiver)
{
	try
	{
		QRegExp regExpMulti(utf8("[0-9]{11}(;[0-9]{11})*(;)?"));
		QRegExp regExpSingle(utf8("[0-9]{11}(;)?"));
		if (multiReceiver && !regExpMulti.exactMatch(self->lineEdit->text()))
			throw Warning("收件人号码格式不正确！");
		if (!multiReceiver && !regExpMulti.exactMatch(self->lineEdit->text()))
			throw Warning("收件人号码格式不正确！");
		if (!multiReceiver && !regExpSingle.exactMatch(self->lineEdit->text()))
			throw Warning("只能指定一个收件人！");

		if (self->plainTextEdit->toPlainText().trimmed().isEmpty())
			throw Warning("短信内容不能为空！");
	}
	catch (...)
	{
		throw;
	}
}

QList<Message> & MyWriteMsg::getMsgs()
{
	try
	{
		QList<Message> * msgs = new QList<Message>;
		Message msg;
		msg.setContent(self->plainTextEdit->toPlainText());

		QStringList receivers = self->lineEdit->text().split(utf8(";"));
		for (int i = 0; i < receivers.length(); ++i)
		{
			if (receivers[i] != utf8(""))
			{
				msg.setReceiverNum(receivers[i]);
				msgs->append(*(new Message(msg)));
			}
		}

		return *msgs;
	}
	catch (...)
	{
		throw;
	}
}
