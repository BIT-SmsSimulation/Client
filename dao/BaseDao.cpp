/**
 * Implementation of BaseDao.
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

#include "BaseDao.h"
#include "../Exception.h"

NS_SMS_BEGIN

BaseDao::BaseDao()
{
	try
	{
		QMutexLocker locker(&mutex);

		if (!connect())
			throw Exception("打开数据库连接失败！");
	}
	catch (...)
	{
		throw;
	}
}

BaseDao::~BaseDao()
{
	QMutexLocker locker(&mutex);
	close();
}

bool BaseDao::connect()
{
	try
	{
#ifdef USE_MDB
		const QString type = utf8("QODBC");
		const QString dbFile = QCoreApplication::applicationDirPath()
			+ utf8("/client.mdb").replace(QChar('/'), QChar('\\'));
		const QString dsn = utf8("DRIVER={Microsoft Access Driver (*.mdb)};")
			+ utf8("FIL={MS Access};DBQ=%1;").arg(dbFile);
#else
		const QString type = utf8("QSQLITE");
		const QString dsn = utf8("db_sms.db");
#endif // USE_MDB
		
		db = QSqlDatabase::database(QSqlDatabase::defaultConnection, false);
		if (db.isValid())
		{
			if (db.isOpen())
			{
				return true;
			}
			return db.open();
		}
		
		db = QSqlDatabase::addDatabase(type, QSqlDatabase::defaultConnection);
		db.setDatabaseName(dsn);
		db.setUserName(utf8("sms_admin"));
		db.setPassword(utf8("*qqe#CytWfiP3TsTx0M"));

		return db.open();
	}
	catch (...)
	{
		throw;
	}
}

bool BaseDao::close()
{
	try
	{
		if (db.isOpen())
			db.close();

		return true;
	}
	catch (...)
	{
		throw;
	}
}

QSqlQuery * BaseDao::executeSql(QString sql)
{
	try
	{
		if (db.isOpen())
		{
			QSqlQuery * query = new QSqlQuery;
			if (query->exec(sql))
				return query;
			else
				throw Exception(query->lastError().text());
		}
		else
			throw Exception("数据库连接未打开！");
	}
	catch (...)
	{
		throw;
	}
}

QSqlQuery * BaseDao::executePreparedSql(QString sql, QList<QVariant> & params)
{
	try
	{
		if (db.isOpen())
		{
			QSqlQuery * query = new QSqlQuery;
			query->prepare(sql);

			for (int i = 0; i < params.length(); ++i)
			{
				query->bindValue(i, params[i]);
			}

			if (query->exec())
				return query;
			else
				throw Exception(query->lastError().text());
		}
		else
			return NULL;
	}
	catch (...)
	{
		throw;
	}
}

#ifndef USE_MDB
bool BaseDao::tableExists(QString tableName)
{
	try
	{
		QString sql = utf8("select count(*) from `sqlite_master` where `type`='table' and `name`='%1'").arg(tableName);
		QSqlQuery * query = executeSql(sql);

		query->next();
		if (query->value(0).toInt() == 0)
			return false;
		else
			return true;
	}
	catch (...)
	{
		throw;
	}
}
#endif // USE_MDB

NS_SMS_END
