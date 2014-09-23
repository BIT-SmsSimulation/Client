#include "MyMsgRecord.h"
#include "MyMsgInfo.h"
#include "../Exception.h"
#include "../service/MessageService.h"

USING_NS_SMS;

MyMsgRecord::MyMsgRecord(ConnectionService * server, QWidget * parent)
	: QDialog(parent), self(new Ui::MsgRecord), server(server)
{
	self->setupUi(this);

	refreshList(Message::SENT);
	refreshList(Message::RECEIVED);
	refreshList(Message::DRAFT);
	refreshList(Message::TIMED);
}

MyMsgRecord::~MyMsgRecord()
{
	delete self;
}
void MyMsgRecord::search()
{
	try
	{
		refreshList(Message::SENT);
		refreshList(Message::RECEIVED);
		refreshList(Message::DRAFT);
		refreshList(Message::TIMED);
	}
	CATCH_BLOCKS
}

void MyMsgRecord::clear()
{
	try
	{
		QString text = utf8("确定清空");
		text += self->tabWidget->tabText(self->tabWidget->currentIndex());
		text += utf8("的短信记录？");

		if (QUESTION(utf8("确认"), text) == QMessageBox::No)
			return;

		int type = getType(self->tabWidget->currentIndex());
		MessageService * msgServer = new MessageService;
		msgServer->deleteMessages(type);
		delete msgServer;

		refreshList(type);
	}
	CATCH_BLOCKS
}

void MyMsgRecord::msgInfo(QListWidgetItem * item)
{
	try
	{
		MyMsgInfo * msgInfoWindow = new MyMsgInfo(server, this, item);
		if (msgInfoWindow->exec() != QDialog::Rejected)
		{
			msgInfoWindow->deleteLater();
			return;
		}
		msgInfoWindow->deleteLater();

		refreshList(Message::SENT);
		refreshList(Message::RECEIVED);
		refreshList(Message::DRAFT);
		refreshList(Message::TIMED);
	}
	CATCH_BLOCKS
}

void MyMsgRecord::refreshList(int type)
{
	try
	{
		MessageService * msgServer = new MessageService;
		QList<Message> list;

		QString keyword = self->lineEdit->text();
		if (keyword.trimmed().isEmpty())
			list = msgServer->getMessages(type);
		else
			list = msgServer->getMessages(type, keyword);
		delete msgServer;

		QListWidget * listWidget = bind(type);
		listWidget->clear();
		for (int i = 0; i < list.length(); ++i)
		{
			QListWidgetItem * item = new QListWidgetItem;

			QString text = list[i].getContent().split(utf8("\n"))[0].left(20);
			if (text.length() < list[i].getContent().length())
				text += utf8("...");
			item->setText(text);

			// Data format: "${id}${endOfMsg}${type}${endOfMsg}${senderNum}${endOfMsg}${receiverNum}${endOfMsg}${time}${endOfMsg}${content}"
			QString data = list[i].getId() + ConnectionService::endOfMsg + QString::number(type);
			data += ConnectionService::endOfMsg + list[i].getSenderNum();
			data += ConnectionService::endOfMsg + list[i].getReceiverNum();
			data += ConnectionService::endOfMsg + list[i].getTime().toString(utf8("yyyy-MM-dd hh:mm:ss"));
			data += ConnectionService::endOfMsg + list[i].getContent();
			item->setData(Qt::UserRole, data);
			listWidget->addItem(item);
		}
	}
	catch (...)
	{
		throw;
	}
}

int MyMsgRecord::getType(int tabIndex)
{
	try
	{
		switch (tabIndex)
		{
		case 0:
			return Message::RECEIVED;

		case 1:
			return Message::SENT;

		case 2:
			return Message::DRAFT;

		case 3:
			return Message::TIMED;

		default:
			throw Exception("非法标签页！");
		}
	}
	catch (...)
	{
		throw;
	}
}

QListWidget * MyMsgRecord::bind(int type)
{
	try
	{
		switch (type)
		{
		case Message::SENT:
			return self->listWidget_2;

		case Message::RECEIVED:
			return self->listWidget;

		case Message::DRAFT:
			return self->listWidget_3;

		case Message::TIMED:
			return self->listWidget_4;

		default:
			throw Exception("非法信息类型！");
		}
	}
	catch (...)
	{
		throw;
	}
}
