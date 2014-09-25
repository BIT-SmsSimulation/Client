/**
 * Implementation of MessageService.
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

#include "MessageService.h"
#include "../Exception.h"

NS_SMS_BEGIN

MessageService::MessageService()
	: dao(new MessageDao)
{
}

MessageService::~MessageService()
{
	delete dao;
}

QList<Message> & MessageService::getMessages(int type)
{
	try
	{
		QMap<QString, QVariant> map;
		map.insert(utf8("TYPE"), type);

		return dao->findByAndMap(map);
	}
	catch (...)
	{
		throw;
	}
}

QList<Message> & MessageService::getMessages(int type, QString keyword)
{
	try
	{
		QMap<QString, QVariant> map;
		map.insert(utf8("TYPE"), type);
		map.insert(utf8("CONTENT"), keyword);

		return dao->findByAndMap(map);
	}
	catch (...)
	{
		throw;
	}
}

bool MessageService::saveMsg(Message & msg)
{
	try
	{
		return dao->save(msg);
	}
	catch (...)
	{
		throw;
	}
}

bool MessageService::editMsg(Message & msg)
{
	try
	{
		if (msg.getType() != Message::DRAFT && msg.getType() != Message::TIMED)
			return false;
		return dao->update(msg);
	}
	catch (...)
	{
		throw;
	}
}

bool MessageService::deleteMessage(QString msgId)
{
	try
	{
		return dao->deleteById(msgId);
	}
	catch(...)
	{
		throw;
	}
}

bool MessageService::deleteMessages(QString contact)
{
	try
	{
		QMap<QString, QVariant> map;
		map.insert(utf8("SENDER_NUM"), contact);
		map.insert(utf8("RECEIVER_NUM"), contact);

		QList<Message> & msgs = dao->findByOrMap(map);

		for (int i = 0; i < msgs.length(); ++i)
		{
			dao->deleteById(msgs[i].getId());
		}
		return true; 
	}
	catch (...)
	{
		throw;
	}
}

bool MessageService::deleteMessages(QList<QString> & msgIds)
{
	try
	{
		for (int i = 0; i < msgIds.length(); ++i)
		{
			dao->deleteById(msgIds[i]);
		}
		return true; 
	}
	catch (...)
	{
		throw;
	}
}

bool MessageService::deleteMessages(int type)
{
	try
	{
		QMap<QString,QVariant> map;
		map.insert(utf8("TYPE"), type);

		QList<Message> & msgs = dao->findByAndMap(map);

		for (int i = 0; i < msgs.length(); ++i)
		{
			dao->deleteById(msgs[i].getId());
		}
		return true;
	}
	catch (...)
	{
		throw;
	}
}

NS_SMS_END
