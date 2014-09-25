/**
 * Receipt model for client.
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
