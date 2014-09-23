/**
 * UI window for write message.
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

#pragma once

#ifndef MY_WRITE_MSG_H_
#define MY_WRITE_MSG_H_

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "WriteMsg.h"

class MyWriteMsg: public QDialog
{
	Q_OBJECT

public:
	MyWriteMsg(ConnectionService * server, QWidget * parent);
	MyWriteMsg(ConnectionService * server, QWidget * parent, QString msgInfo);
	~MyWriteMsg();

public slots:
	void chooseContacts();
	void sendMsg();
	void sendTimedMsg();
	void reject();

private:
	void checkInput(bool multiReceiver = true);
	QList<Message> & getMsgs();

private:
	Ui::WriteMsg * self;
	ConnectionService * server;
	QString id;
};

#endif // MY_WRITE_MSG_H_
