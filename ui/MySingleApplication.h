/**
 * Customized application wrapper.
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

#ifndef MY_SINGLE_APPLICATION_H_
#define MY_SINGLE_APPLICATION_H_

#include <QtGui/QApplication>
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>

#include "../smsClient.h"

class MySingleApplication: public QApplication
{
	Q_OBJECT

public:
	MySingleApplication(int argc, char ** argv);
	~MySingleApplication();
	bool isRunning();

private:
	QLocalServer * server;
	bool running;
};

#endif // MY_SINGLE_APPLICATION_H_
