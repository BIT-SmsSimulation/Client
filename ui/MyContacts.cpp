/**
 * Implementation of MyContacts.
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

#include "MyContacts.h"
#include "MyContactInfo.h"
#include "../Exception.h"
#include "../service/UserService.h"

USING_NS_SMS;

MyContacts::MyContacts(ConnectionService * server, QWidget * parent)
	: QDialog(parent), self(new Ui::Contacts), server(server)
{
	self->setupUi(this);

	refreshList();
}

MyContacts::~MyContacts()
{
	delete self;
}

void MyContacts::search()
{
	try
	{
		refreshList();
	}
	CATCH_BLOCKS
}

void MyContacts::contactInfo()
{
	try
	{
		MyContactInfo * contactInfoWindow = new MyContactInfo(server, this);
		if (contactInfoWindow->exec() != QDialog::Accepted)
		{
			contactInfoWindow->deleteLater();
			return;
		}
		contactInfoWindow->deleteLater();

		refreshList();
	}
	CATCH_BLOCKS
}

void MyContacts::contactInfo(QListWidgetItem * item)
{
	try
	{
		MyContactInfo * contactInfoWindow = new MyContactInfo(server, this, item);
		if (contactInfoWindow->exec() != QDialog::Accepted)
		{
			contactInfoWindow->deleteLater();
			return;
		}
		contactInfoWindow->deleteLater();

		refreshList();
	}
	CATCH_BLOCKS
}

void MyContacts::refreshList()
{
	try
	{
		UserService * userServer = new UserService;
		QList<User> list;

		QString keyword = self->lineEdit->text();
		if (keyword.trimmed().isEmpty())
			list = userServer->getUsers();
		else
			list = userServer->getUsers(keyword);
		delete userServer;

		self->listWidget->clear();
		for (int i = 0; i < list.length(); ++i)
		{
			// Data format: "${id}${endOfMsg}${contact}"
			QListWidgetItem * item = new QListWidgetItem;
			item->setText(list[i].getName());
			QString data = list[i].getId() + ConnectionService::endOfMsg + list[i].getContact();
			item->setData(Qt::UserRole, data);
			self->listWidget->addItem(item);
		}
	}
	catch (...)
	{
		throw;
	}
}
