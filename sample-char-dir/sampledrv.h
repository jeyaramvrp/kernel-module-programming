#ifndef __SAM_CHAR_DRV__
#define __SAM_CHAR_DRV__

#define DRV_NAME "samplechar"

#define MAJOR_DYNAMIC 0
#define MAJOR_HARDCODE 189

static long sample_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
static int  sample_open(struct inode *inode, struct file *filp);
static int  sample_close(struct inode *inode, struct file *filp);
   
#endif
