/**
 * Customized exception.
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

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <QtGui/QMessageBox>

#include "smsClient.h"

NS_SMS_BEGIN

class Exception
{
public:
	Exception(const char * const & message = "")
		: message(utf8(message))
	{
	}

	Exception(const QString & message = "")
		: message(message)
	{
	}

	const QString & what() const
	{
		return message;
	}

private:
	const QString message;
};

class Success: public Exception
{
public:
	Success(const char * const & message = "")
		: Exception(message)
	{
	}

	Success(const QString & message = "")
		: Exception(message)
	{
	}
};

class Warning: public Exception
{
public:
	Warning(const char * const & message = "")
		: Exception(message)
	{
	}

	Warning(const QString & message = "")
		: Exception(message)
	{
	}
};

NS_SMS_END

#define SUCCESS_P(parent, str) QMessageBox::information(parent, utf8("提示"), str, QMessageBox::NoButton, QMessageBox::Ok)
#define SUCCESS(str) SUCCESS_P(this, str)
#define WARNING_P(parent, str) QMessageBox::warning(parent, utf8("提示"), str, QMessageBox::NoButton, QMessageBox::Ok)
#define WARNING(str) WARNING_P(this, str)
#define ERROR_P(parent, title, str) QMessageBox::critical(parent, title, str, QMessageBox::NoButton, QMessageBox::Ok)
#define ERROR(title, str) ERROR_P(this, title, str)
#define QUESTION_P(parent, title, str) QMessageBox::question(parent, title, str, QMessageBox::Yes, QMessageBox::No)
#define QUESTION(title, str) QUESTION_P(this, title, str)

#define CATCH_BLOCKS catch (Success & s)\
{\
SUCCESS(s.what());\
}\
catch (Warning & w)\
{\
WARNING(w.what());\
}\
catch (Exception & e)\
{\
ERROR(utf8("错误"), e.what());\
}\
catch (...)\
{\
ERROR(utf8("未知错误"), utf8("发生了未知错误！"));\
}

#define CATCH_BLOCKS_OUTER catch (Exception & e)\
{\
Exception * ex = new Exception(e);\
emit(exceptionThrown(ex));\
}

#endif // EXCEPTION_H_
