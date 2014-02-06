#ifndef __SAMPLE_IOCTL_H__
#define __SAMPLE_IOCTL_H__

struct calc
{
	int data1;
	int data2;
	int result;
};

#define SAMPLE_MAGIC 'p'   
#define SAMPLE_IOCTL_ADD             _IOWR(SAMPLE_MAGIC, 0x01, struct calc)
#define SAMPLE_IOCTL_SUB             _IOWR(SAMPLE_MAGIC, 0x02, struct calc)
#define SAMPLE_IOCTL_DIV             _IOWR(SAMPLE_MAGIC, 0x03, struct calc)
#define SAMPLE_IOCTL_MUL             _IOWR(SAMPLE_MAGIC, 0x04, struct calc)

#endif
