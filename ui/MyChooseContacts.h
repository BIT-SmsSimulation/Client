#pragma once

#ifndef MY_CHOOSE_CONTACTS_H_
#define MY_CHOOSE_CONTACTS_H_

#include "../smsClient.h"
#include "../service/UserService.h"
#include "ChooseContacts.h"

class MyChooseContact: public QDialog
{
	Q_OBJECT

public:
	MyChooseContact(QWidget * parent);
	~MyChooseContact();
	QStringList getChosenContacts();

private:
	Ui::ChooseContacts * self;
};

#endif // MY_CHOOSE_CONTACTS_H_
