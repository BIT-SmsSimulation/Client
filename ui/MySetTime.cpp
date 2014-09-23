/**
 * Implementation of MySetTime.
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

#include "MySetTime.h"
#include "../Exception.h"

USING_NS_SMS;

MySetTime::MySetTime(QWidget * parent)
	: QDialog(parent), self(new Ui::SetTime)
{
	self->setupUi(this);

	self->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

MySetTime::~MySetTime()
{
	delete self;
}

QDateTime MySetTime::getTime()
{
	return self->dateTimeEdit->dateTime();
}

void MySetTime::accept()
{
	try
	{
		if (self->dateTimeEdit->dateTime().msecsTo(QDateTime::currentDateTime()) > 0)
			throw Warning("发送时间不能早于当前时间！");

		QDialog::accept();
	}
	CATCH_BLOCKS
}
