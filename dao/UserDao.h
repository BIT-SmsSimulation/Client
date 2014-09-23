/**
 * Database access object for User
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

	/**
	 * 根据ID获取联系人
	 */
	User & getById(QString id);

	/**
	 * 根据ID删除联系人
	 */
	bool deleteById(QString id);

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
