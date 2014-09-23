/**
 * Service layer object for User
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
