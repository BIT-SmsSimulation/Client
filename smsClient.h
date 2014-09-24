/**
 * The whole client project include file
 */

#pragma once

#ifndef SMS_CLIENT_H_
#define SMS_CLIENT_H_

#include <QtCore/QtCore>

#define NS_SMS_CLIENT namespace SmsClient
#define NS_SMS_BEGIN NS_SMS_CLIENT {
#define NS_SMS_END }
#define USING_NS_SMS using NS_SMS_CLIENT

#define utf8(str) QString::fromUtf8(str)

#ifdef _WIN32
#define USE_MDB
#endif // _WIN32

#endif // SMS_CLIENT_H_

