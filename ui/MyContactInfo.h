#pragma once

#ifndef MY_CONTACT_INFO_H_
#define MY_CONTACT_INFO_H_

#include <QtGui/QListWidget>

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "ContactInfo.h"

class MyContactInfo: public QDialog
{
	Q_OBJECT

public:
	MyContactInfo(ConnectionService * server, QWidget * parent, QListWidgetItem * item = NULL);
	~MyContactInfo();

public slots:
	void sendMsg();
	void deleteContact();
	void reject();

private:
	void checkInput(bool checkName = true);

private:
	Ui::ContactInfo * self;
	ConnectionService * server;
	QString id;
	QString name;
	QString contact;
};

#endif // MY_CONTACT_INFO_H_
