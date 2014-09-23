#pragma once

#ifndef MY_SET_TIME_H_
#define MY_SET_TIME_H_

#include "../smsClient.h"
#include "SetTime.h"

class MySetTime: public QDialog
{
	Q_OBJECT

public:
	MySetTime(QWidget * parent);
	~MySetTime();
	QDateTime getTime();

public slots:
	void accept();

private:
	Ui::SetTime * self;
};


#endif // MY_SET_TIME_H_
