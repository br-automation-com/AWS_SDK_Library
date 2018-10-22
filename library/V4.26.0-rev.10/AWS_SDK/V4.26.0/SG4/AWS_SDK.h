/* Automation Studio generated header file */
/* Do not edit ! */
/* AWS_SDK 4.26.0 */

#ifndef _AWS_SDK_
#define _AWS_SDK_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _AWS_SDK_VERSION
#define _AWS_SDK_VERSION 4.26.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG4
		#include "astime.h"
		#include "AsHW.h"
		#include "AsHost.h"
		#include "AsETH.h"
		#include "sys_lib.h"
		#include "FileIO.h"
		#include "ArEventLog.h"
		#include "AsIecCon.h"
#endif
#ifdef _SG3
		#include "astime.h"
		#include "AsHW.h"
		#include "AsHost.h"
		#include "AsETH.h"
		#include "sys_lib.h"
		#include "FileIO.h"
		#include "ArEventLog.h"
		#include "AsIecCon.h"
#endif
#ifdef _SGC
		#include "astime.h"
		#include "AsHW.h"
		#include "AsHost.h"
		#include "AsETH.h"
		#include "sys_lib.h"
		#include "FileIO.h"
		#include "ArEventLog.h"
		#include "AsIecCon.h"
#endif

/* Datatypes and datatypes of function blocks */
typedef struct AWS_SDK_Init
{
	/* VAR_INPUT (analog) */
	plcstring Host[257];
	unsigned short Port;
	plcstring ClientID[257];
	plcstring MyThingName[257];
	plcstring RootCAFileName[257];
	plcstring CertificateFileName[257];
	plcstring PrivateKeyFileName[257];
	unsigned long MainThread;
	unsigned long MainParam;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	plcstring ErrorInfo[81];
	/* VAR_INPUT (digital) */
	plcbit EnableLogger;
	plcbit SuspendThread;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Error;
} AWS_SDK_Init_typ;

typedef struct AWS_SDK_Cyclic
{
	/* VAR_INPUT (analog) */
	unsigned char LoggerLevel;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	unsigned char _LoggerLevel;
	/* VAR_INPUT (digital) */
	plcbit Resume;
	plcbit Suspend;
	/* VAR_OUTPUT (digital) */
	plcbit Running;
	/* VAR (digital) */
	plcbit _Resume;
	plcbit _Suspend;
} AWS_SDK_Cyclic_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void AWS_SDK_Init(struct AWS_SDK_Init* inst);
_BUR_PUBLIC void AWS_SDK_Cyclic(struct AWS_SDK_Cyclic* inst);
_BUR_PUBLIC plcbit AWS_SDK_Exit(void);
_BUR_PUBLIC plcbit AWS_SDK_Sleep(unsigned long Milliseconds);
_BUR_PUBLIC unsigned char AWS_SDK_IsAlive(void);


#ifdef __cplusplus
};
#endif
#endif /* _AWS_SDK_ */

