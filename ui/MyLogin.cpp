#include "MyLogin.h"
#include "../Exception.h"

USING_NS_SMS;

MyLogin::MyLogin(QWidget * parent)
	: QDialog(parent), self(new Ui::Login)
{
	self->setupUi(this);
}

MyLogin::~MyLogin()
{
	delete self;
}

QString MyLogin::getPhoneNum()
{
	return self->lineEdit->text();
}

QString MyLogin::getServerIp()
{
	try
	{
		QString ip = self->lineEdit_2->text();
		ip += utf8(".") + self->lineEdit_3->text();
		ip += utf8(".") + self->lineEdit_4->text();
		ip += utf8(".") + self->lineEdit_5->text();
		return ip;
	}
	catch (...)
	{
		throw;
	}
}

void MyLogin::login()
{
	try
	{
		checkInput();
		this->accept();
	}
	CATCH_BLOCKS
}

void MyLogin::checkInput()
{
	try
	{
		QRegExp regExp(utf8("[0-9]{11}"));
		if (!regExp.exactMatch(self->lineEdit->text()))
			throw Warning("请输入正确的号码！");

		bool ok = false;
		int byte = self->lineEdit_2->text().toInt(&ok);
		if (!ok || byte < 0 || byte > 255)
			throw Warning("请输入正确的IP地址！");
		byte = self->lineEdit_3->text().toInt(&ok);
		if (!ok || byte < 0 || byte > 255)
			throw Warning("请输入正确的IP地址！");
		byte = self->lineEdit_4->text().toInt(&ok);
		if (!ok || byte < 0 || byte > 255)
			throw Warning("请输入正确的IP地址！");
		byte = self->lineEdit_5->text().toInt(&ok);
		if (!ok || byte < 0 || byte > 255)
			throw Warning("请输入正确的IP地址！");
	}
	catch (...)
	{
		throw;
	}
}
