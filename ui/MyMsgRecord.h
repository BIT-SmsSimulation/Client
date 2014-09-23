#pragma once

#ifndef MY_MSG_RECORD_H_
#define MY_MSG_RECORD_H_

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "MsgRecord.h"

class MyMsgRecord: public QDialog
{
	Q_OBJECT

public:
	MyMsgRecord(ConnectionService * server, QWidget * parent);
	~MyMsgRecord();

public slots:
	void search();
	void clear();
	void msgInfo(QListWidgetItem * item);

private:
	void refreshList(int type);
	int getType(int tabIndex);
	QListWidget * bind(int type);

private:
	Ui::MsgRecord * self;
	ConnectionService * server;
};

#endif // MY_MSG_RECORD_H_
