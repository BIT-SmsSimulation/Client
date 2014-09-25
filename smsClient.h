/**
 * The whole client project include file.
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

#endif

