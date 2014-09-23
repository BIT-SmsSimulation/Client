#pragma once

#ifndef MY_MSG_INFO_H_
#define MY_MSG_INFO_H_

#include <QtGui/QListWidget>

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "MsgInfo.h"

class MyMsgInfo: public QDialog
{
	Q_OBJECT

public:
	MyMsgInfo(ConnectionService * server, QWidget * parent, QListWidgetItem * item);
	~MyMsgInfo();

public slots:
	void sendMsg();
	void deleteMsg();

private:
	Ui::MsgInfo * self;
	ConnectionService * server;
	QString id;
	QString content;
	QString senderNum;
	QString receiverNum;
	QDateTime time;
	int type;
};

#endif // MY_MSG_INFO_H_
