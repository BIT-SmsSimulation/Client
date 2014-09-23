/**
 * Implementation of MyMainWindow.
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

#include "MyMainWindow.h"
#include "MyWriteMsg.h"
#include "MyContacts.h"
#include "MyMsgRecord.h"
#include "../Exception.h"
#include "../service/MessageService.h"

USING_NS_SMS;

MyMainWindow::MyMainWindow(ConnectionService * server, QWidget * parent)
	: QDialog(parent), self(new Ui::MainWindow), server(server),
	processTimeoutMsg(false), processNewMsg(false), processNewRcp(false)
{
	self->setupUi(this);
}

MyMainWindow::~MyMainWindow()
{
	delete self;

	qDeleteAll(timeoutMsgs);
	qDeleteAll(newMsgs);
	qDeleteAll(newRcps);
}

void MyMainWindow::writeMsg()
{
	try
	{
		MyWriteMsg * writeMsgWindow = new MyWriteMsg(server, this);
		writeMsgWindow->exec();
		writeMsgWindow->deleteLater();
	}
	CATCH_BLOCKS
}

void MyMainWindow::contacts()
{
	try
	{
		MyContacts * contactsWindow = new MyContacts(server, this);
		contactsWindow->exec();
		contactsWindow->deleteLater();
	}
	CATCH_BLOCKS
}

void MyMainWindow::msgRecord()
{
	try
	{
		MyMsgRecord * msgRecordWindow = new MyMsgRecord(server, this);
		msgRecordWindow->exec();
		msgRecordWindow->deleteLater();
	}
	CATCH_BLOCKS
}

void MyMainWindow::dealTimeoutMsg(Message * msg)
{
	try
	{
		timeoutMsgs.append(msg);

		if (processTimeoutMsg)
			return;
		processTimeoutMsg = true;

		MessageService * msgServer = new MessageService;
		while (!timeoutMsgs.isEmpty())
		{
			msg = timeoutMsgs[0];
			msgServer->deleteMessage(msg->getId());

			if (QUESTION(utf8("提醒"), utf8("您有定时短信已超时，是否继续发送？")) == QMessageBox::Yes)
			{
				// msgInfo format: "${receiverNum}${endOfMsg}${content}"
				QString msgInfo = msg->getReceiverNum() + ConnectionService::endOfMsg + msg->getContent();

				MyWriteMsg * writeMsg = new MyWriteMsg(server, this, msgInfo);
				writeMsg->exec();
				writeMsg->deleteLater();
			}
			delete msg;
			timeoutMsgs.removeFirst();
		}
		delete msgServer;
		processTimeoutMsg = false;
	}
	CATCH_BLOCKS
}

void MyMainWindow::dealNewMessage(Message * msg)
{
	try
	{
		newMsgs.append(msg);

		if (processNewMsg)
			return;
		processNewMsg = true;

		MessageService * msgServer = new MessageService;
		while (!newMsgs.isEmpty())
		{
			msg = newMsgs[0];
			msgServer->saveMsg(*msg);

			QString str = utf8("您收到一条来自") + msg->getSenderNum();
			str += utf8("的短信，请在收件箱中查看短信详情！");

			delete msg;
			SUCCESS(str);
			newMsgs.removeFirst();
		}
		delete msgServer;
		processNewMsg = false;
	}
	CATCH_BLOCKS
}

void MyMainWindow::dealNewReceipt(Receipt * rcp)
{
	try
	{
		newRcps.append(rcp);

		if (processNewRcp)
			return;
		processNewRcp = true;

		while (!newRcps.isEmpty())
		{
			rcp = newRcps[0];

			QString str = utf8("您发送给") + rcp->getPhoneNum() + utf8("的短信");
			switch (rcp->getResult())
			{
			case Receipt::Success:
				str += utf8("已经安全送达！");
				break;

			case Receipt::Sending:
				str += utf8("因对方已经关机尚未送达！");
				break;

			case Receipt::Delay:
				str += utf8("经过延迟已经安全送达！");
				break;

			default:
				delete &rcp;
				throw Exception("非法回执类型！");
			}
			delete rcp;
			SUCCESS(str);
			newRcps.removeFirst();
		}
		processNewRcp = false;;
	}
	CATCH_BLOCKS
}

void MyMainWindow::dealException(Exception * e)
{
	try
	{
		throw *e;
	}
	CATCH_BLOCKS

	delete e;
}
