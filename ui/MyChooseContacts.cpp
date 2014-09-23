#include "MyChooseContacts.h"
#include "../Exception.h"

USING_NS_SMS;

MyChooseContact::MyChooseContact(QWidget * parent)
	: QDialog(parent), self(new Ui::ChooseContacts)
{
	self->setupUi(this);

	UserService * server = new UserService;
	QList<User> users = server->getUsers();
	delete server;

	// Data format: "${id};${contact}"
	for (int i = 0; i < users.length(); ++i)
	{
		QListWidgetItem * item = new QListWidgetItem(users[i].getName());
		item->setCheckState(Qt::Unchecked);
		item->setData(Qt::UserRole, users[i].getId() + utf8(";") + users[i].getContact());
		self->listWidget->addItem(item);
	}
}

MyChooseContact::~MyChooseContact()
{
	delete self;
}

QStringList MyChooseContact::getChosenContacts()
{
	try
	{
		QStringList strList;

		for (int i = 0; i < self->listWidget->count(); ++i)
		{
			if (self->listWidget->item(i)->checkState() == Qt::Checked)
			{
				QString data = self->listWidget->item(i)->data(Qt::UserRole).toString();
				strList.append(data.split(utf8(";"))[1]);
			}
		}

		return strList;
	}
	catch (...)
	{
		throw;
	}
}
