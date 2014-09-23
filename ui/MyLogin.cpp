/**
 * Implementation of MyLogin.
 * 
 * Copyright (c) 2014 BIT-SmsSimulation.
 * 
 * This file is part of BIT-SmsSimulation.
 * 
 * BIT-SmsSimulation is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * BIT-SmsSimulation is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with BIT-SmsSimulation.  If not, see <http://www.gnu.org/licenses/>.
 */

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
