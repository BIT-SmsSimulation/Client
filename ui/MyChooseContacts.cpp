/**
 * Implementation of MyChooseContacts.
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

#include "MyChooseContacts.h"
#include "../Exception.h"

USING_NS_SMS;

MyChooseContact::MyChooseContact(QWidget * parent)
	: QDialog(parent), self(new Ui::ChooseContacts)
{
	self->setupUi(this);

	UserService * server = new UserService;
	QList<User> users = server->getUsers();
	delete server;

	// Data format: "${id};${contact}"
	for (int i = 0; i < users.length(); ++i)
	{
		QListWidgetItem * item = new QListWidgetItem(users[i].getName());
		item->setCheckState(Qt::Unchecked);
		item->setData(Qt::UserRole, users[i].getId() + utf8(";") + users[i].getContact());
		self->listWidget->addItem(item);
	}
}

MyChooseContact::~MyChooseContact()
{
	delete self;
}

QStringList MyChooseContact::getChosenContacts()
{
	try
	{
		QStringList strList;

		for (int i = 0; i < self->listWidget->count(); ++i)
		{
			if (self->listWidget->item(i)->checkState() == Qt::Checked)
			{
				QString data = self->listWidget->item(i)->data(Qt::UserRole).toString();
				strList.append(data.split(utf8(";"))[1]);
			}
		}

		return strList;
	}
	catch (...)
	{
		throw;
	}
}
