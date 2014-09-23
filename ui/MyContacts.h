#pragma once

#ifndef MY_CONTACTS_H_
#define MY_CONTACTS_H_

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "Contacts.h"

class MyContacts: public QDialog
{
	Q_OBJECT

public:
	MyContacts(ConnectionService * server, QWidget * parent);
	~MyContacts();

public slots:
	void search();
	void contactInfo();
	void contactInfo(QListWidgetItem * item);

private:
	void refreshList();

private:
	Ui::Contacts * self;
	ConnectionService * server;
};

#endif // MY_CONTACTS_H_
