/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file aws_iot_log.h
 * @brief Logging macros for the SDK.
 * This file defines common logging macros with log levels to be used within the SDK.
 * These macros can also be used in the IoT application code as a common way to output
 * logs.  The log levels can be tuned by modifying the makefile.  Removing (commenting
 * out) the IOT_* statement in the makefile disables that log level.
 *
 * It is expected that the macros below will be modified or replaced when porting to
 * specific hardware platforms as printf may not be the desired behavior.
 */

#ifndef _IOT_LOG_H
#define _IOT_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <ar/logger.h>

/**
 * @brief Debug level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */

#define DEBUG(...)    \
    {\
    	ArAwsConsoleLoggerLog(LOG_DEBUG, __FILE__ ,__PRETTY_FUNCTION__, __LINE__, LOG_LINE, __VA_ARGS__);\
    }

/**
 * @brief Info level logging macro.
 *
 * Macro to expose desired log message.  Info messages do not include automatic function names and line numbers.
 */
#define INFO(...)    \
    {\
    	ArAwsConsoleLoggerLog(LOG_INFO, __FILE__ ,__PRETTY_FUNCTION__, __LINE__, LOG_LINE, __VA_ARGS__);\
    }

/**
 * @brief Warn level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#define WARN(...)   \
    { \
		ArAwsConsoleLoggerLog(LOG_WARNING, __FILE__ ,__PRETTY_FUNCTION__, __LINE__, LOG_LINE, __VA_ARGS__);\
    }

/**
 * @brief Error level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#define ERROR(...)  \
    { \
    	ArAwsConsoleLoggerLog(LOG_ERROR, __FILE__ ,__PRETTY_FUNCTION__, __LINE__, LOG_LINE, __VA_ARGS__);\
		ArAwsLogSSLErrors();\
    }

#endif // _IOT_LOG_H