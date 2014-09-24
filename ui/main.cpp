/**
 * Client side app entry.
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

#include "../smsClient.h"
#include "../Exception.h"
#include "MySingleApplication.h"
#include "MyLogin.h"
#include "MyMainWindow.h"

USING_NS_SMS;

Q_DECLARE_METATYPE(Message *);
Q_DECLARE_METATYPE(Receipt *);
Q_DECLARE_METATYPE(Exception *);

int main(int argc, char * argv[])
{
	MySingleApplication app(argc, argv);
	if (app.isRunning())
	{
		ERROR_P(NULL, utf8("错误"), utf8("同时只能运行一个实例！"));
		return 0;
	}

	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	qRegisterMetaType<Message *>();
	qRegisterMetaType<Receipt *>();
	qRegisterMetaType<Exception *>();

	MyLogin * login = new MyLogin;
	if (login->exec() != QDialog::Accepted)
	{
		login->deleteLater();
		return 0;
	}
	
	QString phoneNum = login->getPhoneNum();
	QString serverIp = login->getServerIp();
	login->deleteLater();

	ConnectionService * server = new ConnectionService(phoneNum, serverIp);
	server->startService();

	MyMainWindow * mainWindow = new MyMainWindow(server);
	server->connectGuiPartTo(mainWindow);
	mainWindow->exec();
	server->ShutdownService();

	mainWindow->deleteLater();
	server->deleteLater();
	return 0;
}
