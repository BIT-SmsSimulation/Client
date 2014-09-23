/**
 * Service layer object for connection
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
