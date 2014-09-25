/**
 * Service layer object for connection.
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

#ifndef CONNECTION_SERVICE_H_
#define CONNECTION_SERVICE_H_

#include <QtNetwork/QtNetwork>

#include "../smsClient.h"
#include "../Exception.h"
#include "../model/Message.h"
#include "../model/Receipt.h"

USING_NS_SMS;

class ConnectionService: public QThread
{
Q_OBJECT

public:
	const static QString endOfMsg;
	const static int sendPort = 3415;
	const static int receivePort = 3416;

public:
	ConnectionService(const QString & phoneNum, const QString & serverIp, QObject * parent = NULL);
	~ConnectionService();
	QString getPhoneNum();
	void connectGuiPartTo(QWidget * widget);

public:
	void startService();
	void ShutdownService();
	void sendMessage(Message & msg);
	void sendMessages(QList<Message> & msgs);

protected slots:
	void send();
	void read();
	void startListen();
	void login();
	void logoff();
	void sendMsg(Message * msg);

protected:
	virtual void run();

signals:
	void sendingMsg(Message * msg);
	void timeoutMsg(Message * msg);
	void newMessage(Message * msg);
	void newReceipt(Receipt * rcp);
	void exceptionThrown(Exception * e);

private:
	QString phoneNum;
	QString serverIp;
	QTcpServer * server;
	QTcpSocket * socket;
	QString content;
};

#endif // CONNECTION_SERVICE_H_
