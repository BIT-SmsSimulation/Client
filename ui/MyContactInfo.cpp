/**
 * Implementation of MyContactInfo.
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

#include "MyContactInfo.h"
#include "MyWriteMsg.h"
#include "../Exception.h"
#include "../service/UserService.h"

USING_NS_SMS;

MyContactInfo::MyContactInfo(ConnectionService * server, QWidget * parent, QListWidgetItem * item)
	: QDialog(parent), self(new Ui::ContactInfo), server(server)
{
	self->setupUi(this);

	if (item != NULL)
	{
		// Data format: "${id}${endOfMsg}${contact}"
		QStringList strList = item->data(Qt::UserRole).toString().split(ConnectionService::endOfMsg);
		id = strList[0];
		contact = strList[1];
		name = item->text();

		self->lineEdit->setText(name);
		self->lineEdit_2->setText(contact);

		this->setWindowTitle(utf8("编辑联系人"));
	}
	else
	{
		this->setWindowTitle(utf8("添加联系人"));
		self->pushButton_2->hide();
	}
}

MyContactInfo::~MyContactInfo()
{
	delete self;
}

void MyContactInfo::sendMsg()
{
	try
	{
		checkInput(false);

		// msgInfo format: "${receiverNum}${endOfMsg}${content}"
		QString msgInfo;
		if (id.isEmpty())
			msgInfo += self->lineEdit_2->text();
		else
			msgInfo += contact;
		msgInfo += ConnectionService::endOfMsg;

		MyWriteMsg * writeMsg = new MyWriteMsg(server, this, msgInfo);
		writeMsg->exec();
		writeMsg->deleteLater();
	}
	CATCH_BLOCKS
}

void MyContactInfo::deleteContact()
{
	try
	{
		if (QUESTION(utf8("确认"), utf8("确定删除该联系人？")) == QMessageBox::No)
			return;

		if (id.isEmpty())
			throw Exception("发生了未知错误！");

		UserService * userServer = new UserService;
		if (!userServer->deleteUser(id))
		{
			delete userServer;
			throw Exception("删除联系人失败！");
		}
		
		delete userServer;
		this->accept();
	}
	CATCH_BLOCKS
}

void MyContactInfo::reject()
{
	try
	{
		if (id.isEmpty() && self->lineEdit->text().trimmed().isEmpty()
			&& self->lineEdit_2->text().trimmed().isEmpty())
		{
			QDialog::reject();
			return;
		}

		if (!id.isEmpty() && name == self->lineEdit->text() && contact == self->lineEdit_2->text())
		{
			QDialog::reject();
			return;
		}

		QString str;
		if (id.isEmpty())
			str = utf8("是否保存该联系人？");
		else
			str = utf8("是否保存修改？");

		if (QUESTION(utf8("提醒"), str) == QMessageBox::No)
		{
			QDialog::reject();
			return;
		}

		checkInput();

		User user;
		user.setName(self->lineEdit->text());
		user.setContact(self->lineEdit_2->text());

		UserService * userServer = new UserService;
		if (id.isEmpty())
		{
			if (!userServer->addUser(user))
			{
				delete userServer;
				throw Exception("添加联系人失败！");
			}
		}
		else
		{
			user.setId(id);
			if (!userServer->editUser(user))
			{
				delete userServer;
				throw Exception("修改联系人失败！");
			}
		}
		delete userServer;

		QDialog::accept();
	}
	CATCH_BLOCKS
}

void MyContactInfo::checkInput(bool checkName)
{
	try
	{
		QRegExp regExpName(utf8("(.){1,15}"));
		if (checkName && !regExpName.exactMatch(self->lineEdit->text().trimmed()))
		{
			throw Warning("请输入合理的联系人姓名！");
		}

		QRegExp regExpContact(utf8("[0-9]{11}"));
		if (!regExpContact.exactMatch(self->lineEdit_2->text()))
		{
			throw Warning("请输入正确的手机号！");
		}
	}
	catch (...)
	{
		throw;
	}
}
