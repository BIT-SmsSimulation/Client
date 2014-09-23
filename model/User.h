/**
 * User model for client
 */

#pragma once

#ifndef USER_H_
#define USER_H_

#include "../smsClient.h"

NS_SMS_BEGIN

class User
{
public:
	const static QString className;

private:
	QString id;			// ID
	QString name;		// 姓名
	QString contact;	// 手机号

public:
	void setId(QString id);
	QString getId() const;
	void setName(QString name);
	QString getName() const;
	void setContact(QString contact);
	QString getContact() const;
};

NS_SMS_END

#endif // USER_H_

