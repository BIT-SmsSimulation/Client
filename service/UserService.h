/**
 * Service layer object for User.
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

#ifndef USER_SERVICE_H_
#define USER_SERVICE_H_

#include "../smsClient.h"
#include "../model/User.h"
#include "../dao/UserDao.h"

NS_SMS_BEGIN

class UserService
{
public:
	UserService();
	~UserService();

	/**
	 * 获取所有联系人
	 */
	QList<User> & getUsers();

	/**
	 * 根据关键字搜索联系人
	 */
	QList<User> & getUsers(QString keyword);

	/**
	 * 添加联系人
	 */
	bool addUser(User & user);

	/**
	 * 删除联系人
	 */
	bool deleteUser(QString userId);

	/**
	 * 编辑联系人
	 */
	bool editUser(User & user);

private:
	UserDao * dao;
};

NS_SMS_END

#endif // USER_SERVICE_H_
