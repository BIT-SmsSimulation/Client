/**
 * Implementation of MessageDao.
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

#include "MessageDao.h"
#include "../Exception.h"

NS_SMS_BEGIN

Message & MessageDao::getById(QString id)
{
	try
	{
		QString sql = utf8("select * from `");
		sql += Message::className + utf8("` where `ID`='");
		sql += id + utf8("';");

		QSqlQuery * query = executeSql(sql);

		QList<Message> & result = getQueryResult(query);
		if (result.length() > 0)
		{
			return result[0];
		}
		else
		{
			throw Exception("短信记录不存在！");
		}
	}
	catch (...)
	{
		throw;
	}
}

bool MessageDao::deleteById(QString id)
{
	try
	{
		QString sql = utf8("delete from `");
		sql += Message::className + utf8("` where `ID`='");
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

bool MessageDao::deleteAll()
{
	try
	{
		QString sql = utf8("delete from `") + Message::className + utf8("`;");

		QSqlQuery * query = executeSql(sql);
		delete query;
		return true;
	}
	catch (...)
	{
		throw;
	}
}

bool MessageDao::save(Message & entity)
{
	try
	{
		entity.setId(QUuid::createUuid().toString().remove(utf8("{")).remove(utf8("}")));

		QString sql = utf8("insert into `") + Message::className;
		sql += utf8("` (`ID`,`CONTENT`,`SENDER_NUM`,`RECEIVER_NUM`,`TIME`,`TYPE`) values(?,?,?,?,?,?);");
		QList<QVariant> params;
		params.append(entity.getId());
		params.append(entity.getContent());
		params.append(entity.getSenderNum());
		params.append(entity.getReceiverNum());
		params.append(entity.getTime());
		params.append(entity.getType());

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

bool MessageDao::update(Message & entity)
{
	try
	{
		QString sql = utf8("update `") + Message::className;
		sql += utf8("` set `CONTENT`=?,`SENDER_NUM`=?,`RECEIVER_NUM`=?,`TIME`=?,`TYPE`=? where `ID`=?;");

		QList<QVariant> params;
		params.append(entity.getContent());
		params.append(entity.getSenderNum());
		params.append(entity.getReceiverNum());
		params.append(entity.getTime());
		params.append(entity.getType());
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

QList<Message> & MessageDao::findByAndMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select * from `") + Message::className;

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

QList<Message> & MessageDao::findByOrMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select * from `") + Message::className;

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

QList<Message> & MessageDao::findAll()
{
	try
	{
		QString sql = utf8("select * from `") + Message::className;
		sql += utf8("`;");

		QSqlQuery * query = executeSql(sql);

		return getQueryResult(query);
	}
	catch (...)
	{
		throw;
	}
}

int MessageDao::findCount()
{
	try
	{
		QString sql = utf8("select count(*) from `") + Message::className;
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

int MessageDao::findCountByAndMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select count(*) from `") + Message::className;

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

int MessageDao::findCountByOrMap(const QMap<QString, QVariant> & map)
{
	try
	{
		QString sql = utf8("select count(*) from `") + Message::className;

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
bool MessageDao::createTable()
{
	try
	{
		QString sql = utf8("create table `") + Message::className;
		sql += utf8("` (`ID` char(36) primary key not null,");
		sql += utf8("`CONTENT` text,");
		sql += utf8("`SENDER_NUM` char(11),");
		sql += utf8("`RECEIVER_NUM` char(11),");
		sql += utf8("`TIME` timestamp,");
		sql += utf8("`TYPE` int);");

		executeSql(sql);
		return true;
	}
	catch (...)
	{
		throw;
	}
}
#endif // USE_MDB

QList<Message> & MessageDao::getQueryResult(QSqlQuery * query)
{
	try
	{
		msgs = new QList<Message>;

		while (query->next())
		{
			Message * msg = new Message;
			msg->setId(query->value(0).toString());
			msg->setContent(query->value(1).toString());
			msg->setSenderNum(query->value(2).toString());
			msg->setReceiverNum(query->value(3).toString());
			msg->setTime(query->value(4).toDateTime());
			msg->setType(query->value(5).toInt());
			msgs->push_back(*msg);
		}

		delete query;
		return *msgs;
	}
	catch (...)
	{
		throw;
	}
}

MessageDao::MessageDao()
{
	msgs = NULL;

#ifndef USE_MDB
	if (!tableExists(Message::className))
		createTable();
#endif // USE_MDB
}

MessageDao::~MessageDao()
{
	try
	{
		if (msgs != NULL)
		{
			msgs->clear();
			delete msgs;
		}
	}
	catch (...)
	{
		throw;
	}
}

NS_SMS_END
