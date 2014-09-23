/**
 * UI window for message information.
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

#ifndef MY_MSG_RECORD_H_
#define MY_MSG_RECORD_H_

#include "../smsClient.h"
#include "../service/ConnectionService.h"
#include "MsgRecord.h"

class MyMsgRecord: public QDialog
{
	Q_OBJECT

public:
	MyMsgRecord(ConnectionService * server, QWidget * parent);
	~MyMsgRecord();

public slots:
	void search();
	void clear();
	void msgInfo(QListWidgetItem * item);

private:
	void refreshList(int type);
	int getType(int tabIndex);
	QListWidget * bind(int type);

private:
	Ui::MsgRecord * self;
	ConnectionService * server;
};

#endif // MY_MSG_RECORD_H_
