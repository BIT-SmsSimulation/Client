/**
 * UI window for contacts.
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
