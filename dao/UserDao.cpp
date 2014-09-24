#include "UserDao.h"
#include "../Exception.h"

NS_SMS_BEGIN

User & UserDao::getById(QString id)
{
	try
	{
		QString sql = utf8("select * from `");
		sql += User::className + utf8("` where `ID`='");
		sql += id + utf8("';");

		QSqlQuery * query = executeSql(sql);

		QList<User> & result = getQueryResult(query);
		if (result.length() > 0)
		{
			return result[0];
		}
		else
		{
			throw Exception("对象不存在！");
		}
	}
	catch (...)
	{
		throw;
	}
}

bool UserDao::deleteById(QString id)
{
	try
	{
		QString sql = utf8("delete from `");
		sql += User::className + utf8("` where `ID`='");
		sql += id + utf8("';");

		QSqlQuery * query = executeSql(sql);

		int rowsAffected = query->numRowsAffected();
		delete query;
		if (rowsAffected == 0)
			return false;
		else
			return true;
	}
	catch (...)
	{
		throw;
	}
}

bool UserDao::deleteAll()
{
	try
	{
		QString sql = utf8("delete from `") + User::className + utf8("`;");

		QSqlQuery * query = executeSql(sql);
		delete query;
		return true;
	}
	catch (...)
	{
		throw;
	}
}

bool UserDao::save(User & entity)
{
	try
	{
		entity.setId(QUuid::createUuid().toString().remove(utf8("{")).remove(utf8("}")));

		QString sql = utf8("insert into `") + User::className;
		sql += utf8("` (`ID`,`NAME`,`CONTACT`) values(?,?,?);");

		QList<QVariant> params;
		params.append(entity.getId());
		params.append(entity.getName());
		params.append(entity.getContact());

		QSqlQuery * query = executePreparedSql(sql, params);

		int rowsAffected = query->numRowsAffected();
		delete query;
		if (rowsAffected == 0)
			return false;
		else
			return true;
	}
	catch (...)
	{
		throw;
	}
}

bool UserDao::update(User & entity)
{
	try
	{
		QString sql = utf8("update `") + User::className;
		sql += utf8("` set `NAME`=?,`CONTACT`=? where `ID`=?;");

		QList<QVariant> params;
		params.append(entity.getName());
		params.append(entity.getContact());
		params.append(entity.getId());

		QSqlQuery * query = executePreparedSql(sql, params);

		int rowsAffected = query->numRowsAffected();
		delete query;
		if (rowsAffected == 0)
			return false;
		else
			return true;
	}
	catch (...)
	{
		throw;
	}
}

QList<User> & UserDao::findByAndMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select * from `") + User::className;

		QMapIterator<QString, QVariant> i(map);
		if (i.hasNext())
		{
			sql += utf8("` where `");

			int flag = 0;
			for (; i.hasNext();)
			{
				if (flag == 0)
					flag = 1;
				else
					sql += utf8(" and `");
				sql += i.peekNext().key() + utf8("` like '%");
				sql += i.next().value().toString() + utf8("%'");
			}
			sql += utf8(";");

			QSqlQuery * query = executeSql(sql);

			return getQueryResult(query);
		}
		else
		{
			sql += utf8("`;");

			QSqlQuery * query = executeSql(sql);

			return getQueryResult(query);
		}
	}
	catch (...)
	{
		throw;
	}
}


QList<User> & UserDao::findByOrMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select * from `") + User::className;

		QMapIterator<QString, QVariant> i(map);
		if (i.hasNext())
		{
			sql += utf8("` where `");

			int flag = 0;
			for (; i.hasNext();)
			{
				if (flag == 0)
					flag = 1;
				else
					sql += utf8(" or `");
				sql += i.peekNext().key() + utf8("` like '%");
				sql += i.next().value().toString() + utf8("%'");
			}
			sql += utf8(";");
		}
		else
		{
			sql += utf8("`;");
		}

		QSqlQuery * query = executeSql(sql);

		return getQueryResult(query);
	}
	catch (...)
	{
		throw;
	}
}

QList<User> & UserDao::findAll()
{
	try
	{
		QString sql = utf8("select * from `") + User::className;
		sql += utf8("`;");

		QSqlQuery * query = executeSql(sql);

		return getQueryResult(query);
	}
	catch (...)
	{
		throw;
	}
}

int UserDao::findCount()
{
	try
	{
		QString sql = utf8("select count(*) from `") + User::className;
		sql += utf8("`;");

		QSqlQuery * query = executeSql(sql);

		query->next();
		int count = query->value(0).toInt();
		delete query;
		return count;
	}
	catch (...)
	{
		throw;
	}
}

int UserDao::findCountByAndMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select count(*) from `") + User::className;

		QMapIterator<QString, QVariant> i(map);
		if (i.hasNext())
		{
			sql += utf8("` where `");

			int flag = 0;
			for (; i.hasNext();)
			{
				if (flag == 0)
					flag = 1;
				else
					sql += utf8(" and `");
				sql += i.peekNext().key() + utf8("` like '%");
				sql += i.next().value().toString() + utf8("%'");
			}
			sql += utf8(";");

			QSqlQuery * query = executeSql(sql);

			query->next();
			int count = query->value(0).toInt();
			delete query;
			return count;
		}
		else
		{
			sql += utf8("`;");

			QSqlQuery * query = executeSql(sql);

			query->next();
			int count = query->value(0).toInt();
			delete query;
			return count;
		}
	}
	catch (...)
	{
		throw;
	}
}

int UserDao::findCountByOrMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select count(*) from `") + User::className;

		QMapIterator<QString, QVariant> i(map);
		if (i.hasNext())
		{
			sql += utf8("` where `");

			int flag = 0;
			for (; i.hasNext();)
			{
				if (flag == 0)
					flag = 1;
				else
					sql += utf8(" or `");
				sql += i.peekNext().key() + utf8("` like '%");
				sql += i.next().value().toString() + utf8("%'");
			}
			sql += utf8(";");
		}
		else
		{
			sql += utf8("`;");
		}

		QSqlQuery * query = executeSql(sql);

		query->next();
		int count = query->value(0).toInt();
		delete query;
		return count;
	}
	catch (...)
	{
		throw;
	}
}

#ifndef USE_MDB
bool UserDao::createTable()
{
	try
	{
		QString sql = utf8("create table `") + User::className;
		sql += utf8("` (`ID` char(36) primary key not null,");
		sql += utf8("`NAME` varchar(45),");
		sql += utf8("`CONTACT` char(11));");

		executeSql(sql);
		return true;
	}
	catch (...)
	{
		throw;
	}
}
#endif // USE_MDB

QList<User> & UserDao::getQueryResult(QSqlQuery * query)
{
	try
	{
		users = new QList<User>;

		while (query->next())
		{
			User * user = new User;
			user->setId(query->value(0).toString());
			user->setName(query->value(1).toString());
			user->setContact(query->value(2).toString());
			users->push_back(*user);
		}

		delete query;
		return *users;
	}
	catch (...)
	{
		throw;
	}
}

UserDao::UserDao()
{
	users = NULL;

#ifndef USE_MDB
	if (!tableExists(User::className))
		createTable();
#endif // USE_MDB
}

UserDao::~UserDao()
{
	try
	{
		if (users != NULL)
		{
			users->clear();
			delete users;
		}
	}
	catch (...)
	{
		throw;
	}
}

NS_SMS_END
