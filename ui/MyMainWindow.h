/**
 * UI window for main window.
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

#ifndef MY_MAIN_WINDOW_H_
#define MY_MAIN_WINDOW_H_

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "MainWindow.h"

class MyMainWindow: public QDialog
{
	Q_OBJECT

public:
	MyMainWindow(ConnectionService * server, QWidget * parent = NULL);
	~MyMainWindow();

public slots:
	void writeMsg();
	void contacts();
	void msgRecord();

	void dealTimeoutMsg(Message * msg);
	void dealNewMessage(Message * msg);
	void dealNewReceipt(Receipt * rcp);
	void dealException(Exception * e);

private:
	Ui::MainWindow * self;
	ConnectionService * server;
	QList<Message *> timeoutMsgs;
	QList<Message *> newMsgs;
	QList<Receipt *> newRcps;
	bool processTimeoutMsg;
	bool processNewMsg;
	bool processNewRcp;
};

#endif // MY_MAIN_WINDOW_H_
