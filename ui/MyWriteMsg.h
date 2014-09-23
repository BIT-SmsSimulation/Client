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
