/**
 * UI window for contact information.
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

#ifndef MY_CONTACT_INFO_H_
#define MY_CONTACT_INFO_H_

#include <QtGui/QListWidget>

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "ContactInfo.h"

class MyContactInfo: public QDialog
{
	Q_OBJECT

public:
	MyContactInfo(ConnectionService * server, QWidget * parent, QListWidgetItem * item = NULL);
	~MyContactInfo();

public slots:
	void sendMsg();
	void deleteContact();
	void reject();

private:
	void checkInput(bool checkName = true);

private:
	Ui::ContactInfo * self;
	ConnectionService * server;
	QString id;
	QString name;
	QString contact;
};

#endif // MY_CONTACT_INFO_H_
