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
	 * �������ͻ�ȡ���ż�¼
	 */
	QList<Message> & getMessages(int type);

	/**
	 * ���ݹؼ����������ż�¼
	 */
	QList<Message> & getMessages(int type, QString keyword);

	/**
	 * ������ż�¼
	 */
	bool saveMsg(Message & msg);

	/**
	 * �༭���ż�¼�����޲ݸ�Ͷ�ʱ����
	 */
	bool editMsg(Message & msg);

	/**
	 * ����IDɾ�����ż�¼
	 */
	bool deleteMessage(QString msgId);

	/**
	 * ������ϵ�˺���ɾ�����ż�¼
	 */
	bool deleteMessages(QString contact);

	/**
	 * ����IDɾ���������ż�¼
	 */
	bool deleteMessages(QList<QString> & msgIds);

	/**
	 * ����������ն��ż�¼
	 */
	bool deleteMessages(int type);

private:
	MessageDao * dao;
};

NS_SMS_END

#endif
