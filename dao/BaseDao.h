/**
 * Base class of database access object.
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
