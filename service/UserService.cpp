/**
 * Implementation of UserService.
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

#include "UserService.h"
#include "../Exception.h"

NS_SMS_BEGIN

UserService::UserService()
	: dao(new UserDao)
{
}

UserService::~UserService()
{
	delete dao;
}

QList<User> & UserService::getUsers()
{
	try
	{
		return dao->findAll();
	}
	catch (...)
	{
		throw;
	}
}

QList<User> & UserService::getUsers(QString keyword)
{
	try
	{
		QMap<QString, QVariant> map;
		map.insert(utf8("NAME"), keyword);
		map.insert(utf8("CONTACT"), keyword);

		return dao->findByOrMap(map);
	}
	catch (...)
	{
		throw;
	}
}

bool UserService::addUser(User & user)
{
	try
	{
		return dao->save(user);
	}
	catch (...)
	{
		throw;
	}
}

bool UserService::deleteUser(QString userId)
{
	try
	{
		return dao->deleteById(userId);
	}
	catch (...)
	{
		throw;
	}
}

bool UserService::editUser(User & user)
{
	try
	{
		return dao->update(user);
	}
	catch (...)
	{
		throw;
	}
}

NS_SMS_END
