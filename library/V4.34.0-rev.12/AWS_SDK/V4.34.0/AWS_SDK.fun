
FUNCTION_BLOCK AWS_SDK_Init
	VAR_INPUT
		EnableLogger : BOOL; (*Activate AR Logging: AWS_LOG and enable ERROR messages*)
		Host : STRING[256]; (*Customer specific MQTT HOST. The same will be used for Thing Shadow*)
		Port : UINT; (*default port for MQTT/S: 8883*)
		ClientID : STRING[256]; (* MQTT client ID should be unique for every device*)
		MyThingName : STRING[256]; (*Thing Name of the Shadow this device is associated with*)
		RootCAFileName : STRING[256]; (*Root CA file name, stored under filedevice CERTS*)
		CertificateFileName : STRING[256]; (*device signed certificate file name, stored under filedevice CERTS*)
		PrivateKeyFileName : STRING[256]; (*Device private key filename, stored under filedevice CERTS*)
		MainThread : UDINT; (*Function pointer to main thread with following signature: void main(UDINT param)*)
		MainParam : UDINT; (*Pointer to parameter (structure) passed to the main thread in param*)
		SuspendThread : BOOL; (*Create the main thread in suspended mode,  that you can start it with AWS_SDK_Cyclic.Start. Useful for debugging*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL;
		Error : BOOL; (*Error occured during initialization*)
		Status : UINT; (*Status from RtkCreateTask*)
		ErrorInfo : STRING[80]; (*Error message*)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION AWS_SDK_Exit : BOOL (*Kill the main thread, should be used in _EXIT*)
END_FUNCTION

FUNCTION AWS_SDK_Sleep : BOOL (*Sleep the main thread for a certain period of time (ms)*)
	VAR_INPUT
		Milliseconds : UDINT;
	END_VAR
END_FUNCTION

FUNCTION AWS_SDK_IsAlive : BOOL (*Check whether the SDK_Exit has been called to kill the thread. should be used inside the main while() loop, to disconnect properly if the task is retransferred*)
END_FUNCTION

FUNCTION AWS_SDK_IsReset : BOOL (*It is possible to reset the connection using SDK_Cyclic.Reset, this function can be used to wrap the complete MainTread in a do while(AWS_SDK_IsReset()) in order to reinitialize the connection. In case of a Reset IsAlive() will go low until AWS_SDK_IsReset() is called, to fall out of the inner loops*)
END_FUNCTION

FUNCTION_BLOCK AWS_SDK_Cyclic
	VAR_INPUT
		Resume : BOOL; (*Start the main thread (if not already running)*)
		Suspend : BOOL; (*Pause the main thread from a system perspective, yield everything*)
		Reset : BOOL; (*Reset the Connection. This also resets the IsAlive() flag until AWS_SDK_IsReset() function is called. see that function for more info*)
		LoggerLevel : USINT; (*0:ERROR, 1:WARNING, 2:INFO, 3:DEBUG*)
	END_VAR
	VAR_OUTPUT
		Running : BOOL; (*Main thread is running*)
		Status : UINT; (*Status from Rtk functions*)
	END_VAR
	VAR
		_Resume : BOOL;
		_Suspend : BOOL;
		_Reset : BOOL;
		_LoggerLevel : USINT;
	END_VAR
END_FUNCTION_BLOCK
