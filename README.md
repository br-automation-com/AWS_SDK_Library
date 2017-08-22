# AWS_SDK_Library
Amazon Web Services Library for B&amp;R SG4 targets

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
![](img/user_partition.png)

#### Create a CERTS file device
![](img/file_device.png)

#### Enable DNS Service
![](img/enable_dns.png)

#### Certificate files needed
![](img/cert_files.png)

#### Copy files to USER partition
![](img/transfer_settings.png)


## Getting Started

Now the system is configured to the extent that you can insert the AWS_SDK Library and start creating your IIoT application. The AWS_SDK libary should be inserted as an Exisiting Libary under the Logical view, and then you insert the sample task(s) as Existing programs.

