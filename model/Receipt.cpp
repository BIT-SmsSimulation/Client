#include "Receipt.h"

NS_SMS_BEGIN

const QString Receipt::className = utf8("receipt");

void Receipt::setPhoneNum(QString phoneNum)
{
	this->phoneNum = phoneNum;
}

QString Receipt::getPhoneNum() const
{
	return phoneNum;
}

void Receipt::setResult(int result)
{
	this->result = result;
}

int Receipt::getResult() const
{
	return result;
}

NS_SMS_END
