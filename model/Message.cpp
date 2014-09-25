/**
 * Implementation of Message.
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

#include "Message.h"

NS_SMS_BEGIN

const QString Message::className = utf8("message");

void Message::setId(QString id)
{
	this->id = id;
}

QString Message::getId() const
{
	return id;
}

void Message::setContent(QString content)
{
	this->content = content;
}

QString Message::getContent() const
{
	return content;
}

void Message::setSenderNum(QString senderNum)
{
	this->senderNum = senderNum;
}

QString Message::getSenderNum() const
{
	return senderNum;
}

void Message::setReceiverNum(QString receiverNum)
{
	this->receiverNum = receiverNum;
}

QString Message::getReceiverNum() const
{
	return receiverNum;
}

void Message::setTime(QDateTime time)
{
	this->time = time;
}

QDateTime Message::getTime() const
{
	return time;
}

void Message::setType(int type)
{
	this->type = type;
}

int Message::getType() const
{
	return type;
}

NS_SMS_END
