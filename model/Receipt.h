/**
 * Message model for client
 */

#pragma once

#ifndef RECEIPT_H_
#define RECEIPT_H_

#include "../smsClient.h"

NS_SMS_BEGIN

class Receipt
{
public:
	const static QString className;
	const static int Success = 0;
	const static int Sending = 1;
	const static int Delay = 2;

private:
	QString phoneNum;	// 手机号
	int result;			// 发送结果，0为成功，1为正在发送，2为延迟后成功

public:
	void setPhoneNum(QString phoneNum);
	QString getPhoneNum() const;
	void setResult(int result);
	int getResult() const;
};

NS_SMS_END

#endif // RECEIPT_H_
