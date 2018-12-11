#ifndef _ARLOGGER_H_
#define _ARLOGGER_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
	LOG_ERROR,
	LOG_WARNING,
	LOG_INFO,
	LOG_DEBUG
	
} LOG_CATEGORY;

#define LOG_LINE	10

#define AR_AWS_SDK_VERSION "AWS_SDK version 4.26.0-rev.11"

/*Public API*/
void ArAwsLoggerResetError();
char ArAwsLoggerGetError();
unsigned long ArAwsLoggerGetErrorCounter();
unsigned long ArAwsLoggerInit();

void ArAwsLogError(const char *format, ...);
void ArAwsLogWarning(const char *format, ...);
void ArAwsLogInfo(const char *format, ...);
void ArAwsLogSuccess(const char *format, ...);

/*used by AWS_IOT_LOG*/
void ArAwsLogSSLErrors();
void ArAwsConsoleLoggerLog(LOG_CATEGORY log_category, const char* file, const char* func, const int line, unsigned int options, const char* format, ...);
void ArAwsSetLogLevel(unsigned char level);

#ifdef __cplusplus
}
#endif

#endif
