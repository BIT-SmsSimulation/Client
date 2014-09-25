/**
 * Database access object for User.
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

#ifndef USER_DAO_H_
#define USER_DAO_H_

#include <QtSql/QtSql>

#include "../smsClient.h"
#include "../model/User.h"
#include "BaseDao.h"

NS_SMS_BEGIN

class UserDao: public BaseDao
{
public:
	UserDao();
	~UserDao();

#ifndef USE_MDB
	virtual bool createTable();
#endif // USE_MDB

	/**
	 * 根据ID获取联系人
	 */
	User & getById(QString id);

	/**
	 * 根据ID删除联系人
	 */
	bool deleteById(QString id);

	/**
	 * 删除所有联系人
	 */
	bool deleteAll();

	/**
	 * 保存联系人
	 */
	bool save(User & entity);

	/**
	 * 更新联系人
	 */
	bool update(User & entity);

	/**
	 * 根据Map获取联系人
	 */
	QList<User> & findByAndMap(const QMap<QString, QVariant> & map);

	/**
	 * 根据Map获取联系人
	 */
	QList<User> & findByOrMap(const QMap<QString, QVariant> & map);

	/**
	 * 获取所有联系人
	 */
	QList<User> & findAll();

	/**
	 * 获取所有联系人的数量
	 */
	int findCount();

	/**
	 * 根据Map获取联系人的数量
	 */
	int findCountByAndMap(const QMap<QString, QVariant> & map);

	/**
	 * 根据Map获取联系人的数量
	 */
	int findCountByOrMap(const QMap<QString, QVariant> & map);

private:
	QList<User> & getQueryResult(QSqlQuery * query);
	QList<User> * users;
};

NS_SMS_END

#endif //USER_DAO_H_
