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

