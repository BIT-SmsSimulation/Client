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
		const QString type = utf8("QODBC");
		const QString dbFile = QCoreApplication::applicationDirPath()
			+ utf8("/client.mdb").replace(QChar('/'), QChar('\\'));
		const QString dsn = utf8("DRIVER={Microsoft Access Driver (*.mdb)};")
			+ utf8("FIL={MS Access};DBQ=%1;").arg(dbFile);

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

NS_SMS_END
