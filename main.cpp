#include <QtCore/QtCore>
#include "Exception.h"
#include "service/ConnectionService.h"

USING_NS_SMS;

int main(int argc, char * argv[])
{
	QCoreApplication app(argc, argv);

	try
	{
		ConnectionService * server = new ConnectionService("18906749758", "10.12.38.114");
		server->startService();

		

		app.exec();
		server->ShutdownService();
		return 0;
	}
	catch (Exception & e)
	{
		qDebug() << e.what();
	}

	return 0;
}
