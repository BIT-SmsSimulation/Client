/**
 * Base class of database access object
 */

#pragma once

#ifndef BASE_DAO_H_
#define BASE_DAO_H_

#include <QtSql/QtSql>

#include "../smsClient.h"

NS_SMS_BEGIN

class BaseDao
{
protected:
	BaseDao();
	virtual ~BaseDao();
	bool connect();
	bool close();
	QSqlQuery * executeSql(QString sql);
	QSqlQuery * executePreparedSql(QString sql, QList<QVariant> & params);

#ifndef USE_MDB
	virtual bool createTable() = 0;
	bool tableExists(QString tableName);
#endif // USE_MDB

protected:
	QMutex mutex;

private:
	QSqlDatabase db;
};

NS_SMS_END

#endif // BASE_DAO_H_
