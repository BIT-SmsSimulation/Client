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
