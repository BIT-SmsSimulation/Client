/**
 * Message model for client
 */

#pragma once

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "../smsClient.h"

NS_SMS_BEGIN

class Message
{
public:
	const static QString className;
	const static int SENT = 0;
	const static int RECEIVED = 1;
	const static int DRAFT = 2;
	const static int TIMED = 3;

private:
	QString id;				// ID
	QString content;		// 内容
	QString senderNum;		// 发送者手机号
	QString receiverNum;	// 接收者手机号
	QDateTime time;			// 发送时间、接收时间或定时时间
	int type;				// 类型，0为已发送，1为已接收，2为草稿，3为定时
	
public:
	void setId(QString id);
	QString getId() const;
	void setContent(QString content);
	QString getContent() const;
	void setSenderNum(QString senderNum);
	QString getSenderNum() const;
	void setReceiverNum(QString receiverNum);
	QString getReceiverNum() const;
	void setTime(QDateTime time);
	QDateTime getTime() const;
	void setType(int type);
	int getType() const;
};

NS_SMS_END

#endif // MESSAGE_H_

