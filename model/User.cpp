/**
 * Implementation of User.
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

#include "User.h"

NS_SMS_BEGIN

const QString User::className = utf8("user");

void User::setId(QString id)
{
	this->id = id;
}

QString User::getId() const
{
	return id;
}

void User::setName(QString name)
{
	this->name = name;
}

QString User::getName() const
{
	return name;
}

void User::setContact(QString contact)
{
	this->contact = contact;
}

QString User::getContact() const
{
	return contact;
}

NS_SMS_END
