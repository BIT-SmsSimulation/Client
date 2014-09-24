/**
 * Database access object for Message
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
