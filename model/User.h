/**
 * User model for client.
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

#ifndef USER_H_
#define USER_H_

#include "../smsClient.h"

NS_SMS_BEGIN

class User
{
public:
	const static QString className;

private:
	QString id;			// ID
	QString name;		// 姓名
	QString contact;	// 手机号

public:
	void setId(QString id);
	QString getId() const;
	void setName(QString name);
	QString getName() const;
	void setContact(QString contact);
	QString getContact() const;
};

NS_SMS_END

#endif // USER_H_
