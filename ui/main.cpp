#include "../smsClient.h"
#include "../Exception.h"
#include "MyLogin.h"
#include "MyMainWindow.h"

USING_NS_SMS;

Q_DECLARE_METATYPE(Message *);
Q_DECLARE_METATYPE(Receipt *);
Q_DECLARE_METATYPE(Exception *);

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

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
