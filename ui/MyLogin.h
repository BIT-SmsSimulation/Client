#pragma once

#ifndef MY_LOGIN_H_
#define MY_LOGIN_H_

#include "../smsClient.h"
#include "Login.h"

class MyLogin : public QDialog
{
	Q_OBJECT

public:
	MyLogin(QWidget * parent = NULL);
	~MyLogin();
	QString getPhoneNum();
	QString getServerIp();

public slots:
	void login();

private:
	void checkInput();

private:
	Ui::Login * self;
};

#endif // MY_LOGIN_H_
