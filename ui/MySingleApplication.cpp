/**
 * Implementation of MySingleApplication.
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

#include "MySingleApplication.h"

MySingleApplication::MySingleApplication(int argc, char ** argv)
	: QApplication(argc, argv), server(new QLocalServer(this)), running(false)
{
	QString serverName = QCoreApplication::applicationName();

	QLocalSocket socket;
	socket.connectToServer(serverName);
	if (socket.waitForConnected(500))
	{
		running = true;
		return;
	}

	if (!server->listen(serverName)) {
		if (server->serverError() == QAbstractSocket::AddressInUseError
			&& QFile::exists(server->serverName()))
		{
			QFile::remove(server->serverName());
			server->listen(serverName);
		}
	}
}

MySingleApplication::~MySingleApplication()
{
	delete server;
}

bool MySingleApplication::isRunning()
{
	return running;
}
