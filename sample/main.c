
#include <bur/plctypes.h>
#include <AWS_SDK.h>
#include <string.h>
#include <AsDefault.h>

void sample(unsigned long param);

void _INIT ProgramInit(void)
{
	AWS_SDK_Init_0.EnableLogger = 1;
	strcpy(AWS_SDK_Init_0.Host, ">>>>HOST NAME / URL TO YOUR THING<<<<");
	AWS_SDK_Init_0.Port = 8883;
	strcpy(AWS_SDK_Init_0.ClientID, ">>>>ID OF THE PLC<<<<");
	strcpy(AWS_SDK_Init_0.MyThingName, ">>>>NAME OF THE THING<<<<");
	strcpy(AWS_SDK_Init_0.RootCAFileName, "aws-iot-rootCA.crt");
	strcpy(AWS_SDK_Init_0.CertificateFileName, ">>>>NAME OF THE THING<<<<.cert.pem");
	strcpy(AWS_SDK_Init_0.PrivateKeyFileName, ">>>>NAME OF THE THING<<<<.private.key");
	AWS_SDK_Init_0.MainThread = (UDINT)sample;
	AWS_SDK_Init_0.MainParam = 0;
	AWS_SDK_Init_0.SuspendThread = 1;
	
	AWS_SDK_Init(&AWS_SDK_Init_0);
}


void _CYCLIC ProgramCyclic(void)
{
	AWS_SDK_Cyclic(&AWS_SDK_Cyclic_0);
}

void _EXIT ProgramExit(void)
{
	AWS_SDK_Exit();
}
