/**
 * Database access object for Message.
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

#ifndef MESSAGE_DAO_H_
#define MESSAGE_DAO_H_

#include <QtSql/QtSql>

#include "../smsClient.h"
#include "../model/Message.h"
#include "BaseDao.h"

NS_SMS_BEGIN

class MessageDao: public BaseDao
{
public:
	MessageDao();
	~MessageDao();

#ifndef USE_MDB
	virtual bool createTable();
#endif // USE_MDB

	/**
	 * 根据ID获取短信记录
	 */
	Message & getById(QString id);

	/**
	 * 根据ID删除短信记录
	 */
	bool deleteById(QString id);

	/**
	 * 删除所有短信记录
	 */
	bool deleteAll();

	/**
	 * 保存短信记录
	 */
	bool save(Message & entity);

	/**
	 * 更新短信记录
	 */
	bool update(Message & entity);

	/**
	 * 根据Map获取短信记录
	 */
	QList<Message> & findByAndMap(const QMap<QString, QVariant> & map);

	/**
	 * 根据Map获取短信记录
	 */
	QList<Message> & findByOrMap(const QMap<QString, QVariant> & map);

	/**
	 * 获取所有短信记录
	 */
	QList<Message> & findAll();

	/**
	 * 获取所有短信记录的数量
	 */
	int findCount();

	/**
	 * 根据Map获取短信记录的数量
	 */
	int findCountByAndMap(const QMap<QString, QVariant> & map);

	/**
	 * 根据Map获取短信记录的数量
	 */
	int findCountByOrMap(const QMap<QString, QVariant> & map);

private:
	QList<Message> & getQueryResult(QSqlQuery * query);
	QList<Message> * msgs;
};

NS_SMS_END

#endif // MESSAGE_DAO_H_
