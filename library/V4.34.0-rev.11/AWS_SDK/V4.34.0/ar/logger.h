#ifndef _ARLOGGER_H_
#define _ARLOGGER_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define _EXPORTED __attribute__((visibility("default")))

typedef enum
{
	LOG_ERROR,
	LOG_WARNING,
	LOG_INFO,
	LOG_DEBUG
	
} LOG_CATEGORY;

#define LOG_LINE	10

#define AR_AWS_SDK_VERSION "AWS_SDK version 4.34.0-rev.11"

/*Public API*/
_EXPORTED void ArAwsLoggerResetError();
_EXPORTED char ArAwsLoggerGetError();
_EXPORTED unsigned long ArAwsLoggerGetErrorCounter();
_EXPORTED unsigned long ArAwsLoggerInit();

_EXPORTED void ArAwsLogError(const char *format, ...);
_EXPORTED void ArAwsLogWarning(const char *format, ...);
_EXPORTED void ArAwsLogInfo(const char *format, ...);
_EXPORTED void ArAwsLogSuccess(const char *format, ...);

/*used by AWS_IOT_LOG*/
_EXPORTED void ArAwsLogSSLErrors();
_EXPORTED void ArAwsConsoleLoggerLog(LOG_CATEGORY log_category, const char* file, const char* func, const int line, unsigned int options, const char* format, ...);
_EXPORTED void ArAwsSetLogLevel(unsigned char level);

#ifdef __cplusplus
}
#endif

#endif
