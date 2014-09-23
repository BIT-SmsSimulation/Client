#include "User.h"

NS_SMS_BEGIN

const QString User::className = utf8("user");

void User::setId(QString id)
{
	this->id = id;
}

QString User::getId() const
{
	return id;
}

void User::setName(QString name)
{
	this->name = name;
}

QString User::getName() const
{
	return name;
}

void User::setContact(QString contact)
{
	this->contact = contact;
}

QString User::getContact() const
{
	return contact;
}

NS_SMS_END

