#include "MySetTime.h"
#include "../Exception.h"

USING_NS_SMS;

MySetTime::MySetTime(QWidget * parent)
	: QDialog(parent), self(new Ui::SetTime)
{
	self->setupUi(this);

	self->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

MySetTime::~MySetTime()
{
	delete self;
}

QDateTime MySetTime::getTime()
{
	return self->dateTimeEdit->dateTime();
}

void MySetTime::accept()
{
	try
	{
		if (self->dateTimeEdit->dateTime().msecsTo(QDateTime::currentDateTime()) > 0)
			throw Warning("发送时间不能早于当前时间！");

		QDialog::accept();
	}
	CATCH_BLOCKS
}
