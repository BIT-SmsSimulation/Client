/**
 * Implementation of MyMsgInfo.
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

#include "MyMsgInfo.h"
#include "MyWriteMsg.h"
#include "../Exception.h"
#include "../service/ConnectionService.h"
#include "../service/MessageService.h"

USING_NS_SMS;

MyMsgInfo::MyMsgInfo(ConnectionService * server, QWidget * parent, QListWidgetItem * item)
	: QDialog(parent), self(new Ui::MsgInfo), server(server)
{
	self->setupUi(this);

	// Data format: "${id}${endOfMsg}${type}${endOfMsg}${senderNum}${endOfMsg}${receiverNum}${endOfMsg}${time}${endOfMsg}${content}"
	QStringList strList = item->data(Qt::UserRole).toString().split(ConnectionService::endOfMsg);
	id = strList[0];
	bool ok = false;
	type = strList[1].toInt(&ok);
	if (!ok)
		throw Exception("短信格式错误！");
	time = QDateTime::fromString(strList[4], utf8("yyyy-MM-dd hh:mm:ss"));
	content = strList[5];
	self->plainTextEdit->setPlainText(content);
	
	switch (type)
	{
	case Message::SENT:
		self->label_4->setText(utf8("发送时间"));
		self->pushButton->setText(utf8("转发"));
		// Fall through

	case Message::RECEIVED:
		senderNum = strList[2];
		receiverNum = strList[3];

		self->lineEdit->setText(senderNum);
		self->lineEdit_2->setText(receiverNum);
		self->dateTimeEdit->setDateTime(time);
		break;

	case Message::DRAFT:
		senderNum = server->getPhoneNum();

		self->label_4->setText(utf8("编辑时间"));
		self->pushButton->setText(utf8("编辑"));

		self->lineEdit->setText(senderNum);
		self->dateTimeEdit->setDateTime(time);
		break;

	case Message::TIMED:
		senderNum = server->getPhoneNum();
		receiverNum = strList[3];

		self->label_4->setText(utf8("发送时间"));
		self->pushButton->setText(utf8("编辑"));

		self->lineEdit->setText(senderNum);
		self->lineEdit_2->setText(receiverNum);
		self->dateTimeEdit->setDateTime(time);
		break;

	default:
		throw Exception("非法信息类型！");
	}
}

MyMsgInfo::~MyMsgInfo()
{
	delete self;
}

void MyMsgInfo::sendMsg()
{
	try
	{
		// msgInfo format: "${receiverNum}${endOfMsg}${content}"
		QString msgInfo;

		MyWriteMsg * writeMsg = NULL;
		MessageService * msgServer = NULL;

		switch (type)
		{
		case Message::SENT: // Forward
			msgInfo = ConnectionService::endOfMsg + content;
			writeMsg = new MyWriteMsg(server, this, msgInfo);
			writeMsg->exec();
			writeMsg->deleteLater();
			break;

		case Message::RECEIVED: // Reply
			msgInfo = senderNum + ConnectionService::endOfMsg;
			writeMsg = new MyWriteMsg(server, this, msgInfo);
			writeMsg->exec();
			writeMsg->deleteLater();
			break;

		case Message::DRAFT: // Edit
			msgInfo = ConnectionService::endOfMsg + content;
			writeMsg = new MyWriteMsg(server, this, msgInfo);
			if (writeMsg->exec() == QDialog::Accepted)
			{
				msgServer = new MessageService;
				msgServer->deleteMessage(id);
				delete msgServer;
				this->reject();
			}
			writeMsg->deleteLater();
			break;

		case Message::TIMED: // Edit
			msgInfo = receiverNum + ConnectionService::endOfMsg + content;
			writeMsg = new MyWriteMsg(server, this, msgInfo);
			if (writeMsg->exec() == QDialog::Accepted)
			{
				msgServer = new MessageService;
				msgServer->deleteMessage(id);
				delete msgServer;
				this->reject();
			}
			writeMsg->deleteLater();
			break;

		default:
			throw Exception("非法信息类型！");
		}
	}
	CATCH_BLOCKS
}

void MyMsgInfo::deleteMsg()
{
	try
	{
		if (QUESTION(utf8("确认"), utf8("确定删除该条短信？")) == QMessageBox::No)
			return;

		MessageService * msgServer = new MessageService;
		if (!msgServer->deleteMessage(id))
		{
			delete msgServer;
			throw Exception("删除短信失败！");
		}
		delete msgServer;

		this->reject();
	}
	CATCH_BLOCKS
}
