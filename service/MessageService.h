/**
 * Service layer object for Message
 */

#pragma once

#ifndef MESSAGE_SERVICE_H_
#define MESSAGE_SERVICE_H_

#include "../smsClient.h"
#include "../model/Message.h"
#include "../dao/MessageDao.h"

NS_SMS_BEGIN

class MessageService
{
public:
	MessageService();
	~MessageService();

	/**
	 * 根据类型获取短信记录
	 */
	QList<Message> & getMessages(int type);

	/**
	 * 根据关键字搜索短信记录
	 */
	QList<Message> & getMessages(int type, QString keyword);

	/**
	 * 保存短信记录
	 */
	bool saveMsg(Message & msg);

	/**
	 * 编辑短信记录，仅限草稿和定时短信
	 */
	bool editMsg(Message & msg);

	/**
	 * 根据ID删除短信记录
	 */
	bool deleteMessage(QString msgId);

	/**
	 * 根据联系人号码删除短信记录
	 */
	bool deleteMessages(QString contact);

	/**
	 * 根据ID删除多条短信记录
	 */
	bool deleteMessages(QList<QString> & msgIds);

	/**
	 * 根据类型清空短信记录
	 */
	bool deleteMessages(int type);

private:
	MessageDao * dao;
};

NS_SMS_END

#endif
