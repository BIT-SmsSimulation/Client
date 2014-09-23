#include "ConnectionService.h"
#include "../Exception.h"
#include "../dao/MessageDao.h"

#include "../ui/MyWriteMsg.h"

USING_NS_SMS;

const QString ConnectionService::endOfMsg = utf8("\f");

ConnectionService::ConnectionService(const QString & phoneNum, const QString & serverIp, QObject * parent)
	: QThread(parent), phoneNum(phoneNum), serverIp(serverIp),
	server(new QTcpServer), socket(new QTcpSocket)
{
	connect(server, SIGNAL(newConnection()), this, SLOT(read()));
	connect(this, SIGNAL(sendingMsg(Message *)), this, SLOT(sendMsg(Message *)));
}

ConnectionService::~ConnectionService()
{
	delete server;
	delete socket;
}

QString ConnectionService::getPhoneNum()
{
	return phoneNum;
}

void ConnectionService::connectGuiPartTo(QWidget * widget)
{
	connect(this, SIGNAL(timeoutMsg(Message *)), widget, SLOT(dealTimeoutMsg(Message *)));
	connect(this, SIGNAL(newMessage(Message *)), widget, SLOT(dealNewMessage(Message *)));
	connect(this, SIGNAL(newReceipt(Receipt *)), widget, SLOT(dealNewReceipt(Receipt *)));
	connect(this, SIGNAL(exceptionThrown(Exception *)), widget, SLOT(dealException(Exception *)));
}

void ConnectionService::startService()
{
	startListen();
	login();
	start();
}

void ConnectionService::ShutdownService()
{
	logoff();
}

void ConnectionService::startListen()
{
	try
	{
		if (!server->isListening()
			&& !server->listen(QHostAddress::Any, receivePort))
		{
			throw Exception("监听端口失败！");
		}
	}
	CATCH_BLOCKS_OUTER
}

void ConnectionService::login()
{
	try
	{
		content = utf8("U\n");
		content += phoneNum + utf8("\n");
		content += utf8("login\n");

		send();
	}
	CATCH_BLOCKS_OUTER
}

void ConnectionService::logoff()
{
	try
	{
		content = utf8("U\n");
		content += phoneNum + utf8("\n");
		content += utf8("logoff\n");

		send();
	}
	CATCH_BLOCKS_OUTER
}

void ConnectionService::sendMsg(Message * msg)
{
	sendMessage(*msg);
	delete msg;
}

void ConnectionService::sendMessage(Message & msg)
{
	try
	{
		content = utf8("M\n");
		content += msg.getSenderNum() + utf8("\n");
		content += msg.getReceiverNum() + utf8("\n");
		content += msg.getContent() + utf8("\n");
		content += endOfMsg + utf8("\n");
		
		send();
	}
	CATCH_BLOCKS_OUTER
}

void ConnectionService::sendMessages(QList<Message> & msgs)
{
	try
	{
		content = utf8("");
		for (int i = 0; i < msgs.length(); ++i)
		{
			content += utf8("M\n");
			content += getPhoneNum() + utf8("\n");
			content += msgs[i].getReceiverNum() + utf8("\n");
			content += msgs[i].getContent() + utf8("\n");
			content += endOfMsg + utf8("\n");
		}

		send();
	}
	CATCH_BLOCKS_OUTER
}

void ConnectionService::send()
{
	try
	{
		socket->connectToHost(serverIp, sendPort);
		if (!socket->waitForConnected(2000))
			throw Exception("无法连接到服务器" + serverIp + "！");

		socket->write(content.toUtf8());

		socket->disconnectFromHost();
		if (!socket->waitForDisconnected(2000))
			throw Exception("无法连接到服务器" + serverIp + "！");
	}
	catch (...)
	{
		throw;
	}
}

void ConnectionService::read()
{
	try
	{
		QTcpSocket * serverSocket = server->nextPendingConnection();
		serverSocket->waitForReadyRead();

		QString line;
		while (!(line = utf8(serverSocket->readLine().data())).isEmpty())
		{
			if (line == utf8("M\n"))
			{
				Message * msg = new Message;
				msg->setTime(QDateTime::currentDateTime());
				msg->setType(Message::RECEIVED);

				// Set senderNum
				line = utf8(serverSocket->readLine().data());
				QRegExp regexp("[0-9]{11}\n");
				if (!regexp.exactMatch(line))
					break;
				msg->setSenderNum(line.remove(utf8("\n")));

				// Set receiverNum
				line = utf8(serverSocket->readLine().data());
				if (!regexp.exactMatch(line))
					break;
				msg->setReceiverNum(line.remove(utf8("\n")));

				// Set content
				QString msgContent = "";
				bool newlineFlag = false;
				while ((line = utf8(serverSocket->readLine().data())) != (endOfMsg + utf8("\n")))
				{
					if (!newlineFlag)
					{
						newlineFlag = true;
					}
					else
					{
						msgContent += utf8("\n");
					}
					msgContent += line.remove(utf8("\n"));
				}
				msg->setContent(msgContent);
				emit(newMessage(msg));
			}
			else if (line == utf8("R\n"))
			{
				while (!(line = utf8(serverSocket->readLine().data())).isEmpty())
				{
					QStringList strList = line.remove(utf8("\n")).split(utf8(" "));
					Receipt * rcp = new Receipt;
					rcp->setPhoneNum(strList[0]);
					rcp->setResult(strList[1].toInt());
					emit(newReceipt(rcp));
				}
				break;
			}
		}
	}
	CATCH_BLOCKS_OUTER
}

void ConnectionService::run()
{
	try
	{
		QMap<QString, QVariant> map;
		map.insert(utf8("TYPE"), Message::TIMED);

		while (true)
		{
			MessageDao * dao = new MessageDao;
			QList<Message> & msgs = dao->findByAndMap(map);

			for (int i = 0; i < msgs.length(); ++i)
			{
				int interval = QDateTime::currentDateTime().msecsTo(msgs[i].getTime());
				if (interval < -6000)
				{
					emit(timeoutMsg(new Message(msgs[i])));
				}
				else if (interval < 6000)
				{
					msgs[i].setSenderNum(phoneNum);
					emit(sendingMsg(new Message(msgs[i])));
					msgs[i].setType(Message::SENT);
					dao->update(msgs[i]);
				}
			}
			sleep(10);

			delete dao;
		}
	}
	CATCH_BLOCKS_OUTER
}
