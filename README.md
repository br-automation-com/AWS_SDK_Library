# AWS_SDK_Library
Amazon Web Services Library for B&amp;R SG4 targets

## Version Information
This is a compiled library for B&R SG4 Targets using
[https://github.com/aws/aws-iot-device-sdk-embedded-C](https://github.com/aws/aws-iot-device-sdk-embedded-C), Release of version 1.1.2

All versions will have .0 in the end in Automation Studio

Versions / AR Support:

- V4.26.0-rev.10: Automation Runtime 4.26
	- Updated logging functionality including SSL errors in the AWS_LOG. This version also fixes the problem with errors mistakenly (without there being a problem) popping up in the system logger. 

It has been tested on following hardware / runtime:

 - CP1586 / D4.26


## Prerequisites

To get started with Amazon Webservices, please visit https://aws.amazon.com/iot-platform/getting-started/

On the AWS Management Console, you can create a Thing that you connect your PLC to.

Please read the getting started tutorial, that will guide you through the process.

For the B&amp;R Platform, you basically need

- A Thing registered in the cloud
- Root certificate
- Public certificate and Private key
- The AWS_SDK Library

## Preprarations

The certificates are generated for each thing via the AWS management console, and should be put avialable for your Controller under the filedevice "CERTS". Easiest way to do this, is to copy the folder with the certificates to the USER partition, and create a FileDevice "CERTS" under "F:\". Further, in order to translate the URL to your thing to a network address, you need to enable the DNS service in the controller.

#### Setup a USER partition
![](img/user_partition.PNG)

#### Create a CERTS file device
![](img/file_device.PNG)

#### Enable DNS Service
![](img/enable_dns.PNG)

#### Certificate files needed
![](img/cert_files.PNG)

#### Copy files to USER partition
![](img/transfer_settings.PNG)


## Getting Started

Now the system is configured to the extent that you can insert the AWS_SDK Library and start creating your IIoT application. The AWS_SDK libary should be inserted as an Exisiting Libary under the Logical view, and then you insert the sample task(s) as Existing programs.

#### Insert the AWS_SDK Library

![](img/insert_lib.PNG)

The Version of the Library reflects the Runtime version it is compiled for, in this case, AR4.26.

The Library has dependencies to other B&R Libraries, that will be inserted automatically.

#### Automatically Inserted Libraries
![](img/other_libs.PNG)

All headerfiles you need are part of the AWS_SDK Library, so you just need to setup the compiler to include these files in the build. This can be done on a global level (as in the picture) or on a task-local level.

#### Headerfiles of AWS_SDK

![](img/headers.PNG)

#### Setup the Include directory for the Headers

![](img/compiler.PNG)

Now you are ready to create your IIoT application task. 

## Using the Library

In order to get started, insert the sample task available here as an existing program, and fill out the missing fields marked with ">>>><<<<"

	void sample(unsigned long param); //the aws sample program

	void _INIT ProgramInit(void)
	{
		AWS_SDK_Init_0.EnableLogger = 1;
		strcpy(AWS_SDK_Init_0.Host, ">>>thing host address.amazonaws.com<<<<");
		AWS_SDK_Init_0.Port = 8883;
		strcpy(AWS_SDK_Init_0.ClientID, ">>>>ID of the PLC<<<<");
		strcpy(AWS_SDK_Init_0.MyThingName, ">>>>Name of the Thing in the cloud<<<<");
		strcpy(AWS_SDK_Init_0.RootCAFileName, "aws-iot-rootCA.crt");
		strcpy(AWS_SDK_Init_0.CertificateFileName, "SampleThing.cert.pem");
		strcpy(AWS_SDK_Init_0.PrivateKeyFileName, "SampleThing.private.key");
		AWS_SDK_Init_0.MainThread = (UDINT)sample;
		AWS_SDK_Init_0.MainParam = 0;
		AWS_SDK_Init_0.SuspendThread = 1;
		
		AWS_SDK_Init(&AWS_SDK_Init_0);
	}

The sample itself needs to run as an asynchronous thread, which the Library has already taken into consideration. You therefore pass the function pointer to the sample program to the MainThread Input. If you want, you can also pass other arguments, such as a structure pointer using the MainParam input.

In this case the Logger is enabled, and the sample task starts suspended, therfore you need AWS_SDK_Cyclic to start the thread using the Resume input. With the AWS_SDK_Cyclic.LoggerLevel you can also control which level of logmessages you want to have in the logger. The AWS_Exit is used to shutdown the AWS sample task and kill the thread when the program is redownloaded.

	void _CYCLIC ProgramCyclic(void)
	{
		AWS_SDK_Cyclic(&AWS_SDK_Cyclic_0);
	}

	void _EXIT ProgramExit(void)
	{
		AWS_SDK_Exit();
	}

When you have come this far, you should see the result in the Logger.
![](img/logger.PNG)

The updates are also reflected on your AWS Management platform.
![](img/thing.PNG)
