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
void ArAwsConsoleLoggerLog(LOG_CATEGORY log_category, const char* file, const char* func, const int line, unsigned int options, const char* format, ...);
void ArAwsSetLogLevel(unsigned char level);

#ifdef __cplusplus
}
#endif

#endif
