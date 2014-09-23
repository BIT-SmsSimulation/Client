#include "UserService.h"
#include "../Exception.h"

NS_SMS_BEGIN

UserService::UserService()
	: dao(new UserDao)
{
}

UserService::~UserService()
{
	delete dao;
}

QList<User> & UserService::getUsers()
{
	try
	{
		return dao->findAll();
	}
	catch (...)
	{
		throw;
	}
}

QList<User> & UserService::getUsers(QString keyword)
{
	try
	{
		QMap<QString, QVariant> map;
		map.insert(utf8("NAME"), keyword);
		map.insert(utf8("CONTACT"), keyword);

		return dao->findByOrMap(map);
	}
	catch (...)
	{
		throw;
	}
}

bool UserService::addUser(User & user)
{
	try
	{
		return dao->save(user);
	}
	catch (...)
	{
		throw;
	}
}

bool UserService::deleteUser(QString userId)
{
	try
	{
		return dao->deleteById(userId);
	}
	catch (...)
	{
		throw;
	}
}

bool UserService::editUser(User & user)
{
	try
	{
		return dao->update(user);
	}
	catch (...)
	{
		throw;
	}
}

NS_SMS_END
