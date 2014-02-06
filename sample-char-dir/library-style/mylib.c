#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#include "../sampleioctl.h"
#include "mylib.h"

int fd;
struct calc dat;

int OpenDev()
{
	fd = open("/dev/samplechar", O_RDWR);
	if(fd < 0)
	{
		perror("open:");
    		return -1;
	}
	return 0;
}

int Add(int data1, int data2)
{
	int err=0;
	
	dat.data1 = data1;
	dat.data2 = data2;

	err=ioctl(fd, SAMPLE_IOCTL_ADD, &dat);
	if(err < 0)
	{
		perror("ioctl:");
		return -1;
	}
	return dat.result;
}

int Sub(int data1, int data2)
{
	int err=0;

	dat.data1 = data1;
	dat.data2 = data2;

	err=ioctl(fd, SAMPLE_IOCTL_SUB, &dat);
	if(err < 0)
	{
		perror("ioctl:");
		return -1;
	}
	return dat.result;
}

int Mul(int data1, int data2)
{
	int  err=0;

	dat.data1 = data1;
	dat.data2 = data2;

	err=ioctl(fd, SAMPLE_IOCTL_MUL, &dat);if(err < 0)
	{
		perror("ioctl:");
		return -1;
	}
	return dat.result;
}
int Div(int data1, int data2)
{
	int err=0;

	dat.data1 = data1;
	dat.data2 = data2;

	err= ioctl(fd, SAMPLE_IOCTL_DIV, &dat);
	if(err < 0)
	{
		perror("ioctl:");
		return -1;
	}
	return dat.result;
}

int CloseDev()
{
	close(fd);
	return 0;
}
