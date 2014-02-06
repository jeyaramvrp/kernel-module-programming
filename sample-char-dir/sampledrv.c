#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/fs.h>
#include <linux/init.h>

#include "sampledrv.h"
#include "sampleioctl.h"

MODULE_LICENSE("GPL");
static int major;

static const struct file_operations sample_fops = {
        .owner = THIS_MODULE,
        .unlocked_ioctl = sample_ioctl,
        .open           = sample_open,
        .release        = sample_close
};

int ourinitmodule(void)
{
	major = register_chrdev(MAJOR_DYNAMIC, DRV_NAME, &sample_fops);
        /* major = register_chrdev(MAJOR_HARDCODE, DRV_NAME, &sample_fops);*/
        if (major < 0) {
		printk(KERN_ERR "%s: couldn't get a major number.\n", DRV_NAME);
		return major;
        }

	return 0;
}

void ourcleanupmodule(void)
{
	unregister_chrdev(major, DRV_NAME);
	printk(KERN_ALERT "\n Hello Jay, Thanks....Exiting Application. \n");
}

static long sample_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	switch(cmd) 
        {
		case SAMPLE_IOCTL_ADD:
		{
                	struct calc addition;
			memset(&addition, 0, sizeof(struct calc));
			if (copy_from_user(&addition, (struct calc*)arg,\
							sizeof(struct calc)))
				return -EFAULT;
			
			addition.result = addition.data1 + addition.data2;
			if (copy_to_user((struct calc*)arg, &addition,\
							sizeof(struct calc)))
				return -EFAULT;
			printk(KERN_ALERT "\n Kernel :: Add . \n");
			return 0;
		}

		case SAMPLE_IOCTL_SUB:
		{
			struct calc sub;
			memset(&sub, 0, sizeof(struct calc));
			if (copy_from_user(&sub, (struct calc*)arg,\
							sizeof(struct calc)))
				return -EFAULT;
			sub.result = sub.data1 - sub.data2;
			if (copy_to_user((struct calc*)arg, &sub,\
							sizeof(struct calc)))
				return -EFAULT;
			printk(KERN_ALERT "\n Kernel :: Sub . \n");
			return 0;
		}

		case SAMPLE_IOCTL_MUL:
		{
			struct calc mul;
			memset(&mul, 0, sizeof(struct calc));
			if (copy_from_user(&mul, (struct calc*)arg,\
							sizeof(struct calc)))
				return -EFAULT;

			mul.result = mul.data1 * mul.data2;
			if (copy_to_user((struct calc*)arg, &mul,\
							sizeof(struct calc)))
				return -EFAULT;

			printk(KERN_ALERT "\n Kernel :: MUL . \n");
			return 0;
		}

		case SAMPLE_IOCTL_DIV:
		{
			struct calc div;
			memset(&div, 0, sizeof(struct calc));
			if (copy_from_user(&div, (struct calc*)arg,\
							sizeof(struct calc)))
				return -EFAULT;

			if(div.data2 == 0)
				return 0;

			div.result = div.data1 / div.data2;
			if (copy_to_user((struct calc*)arg, &div,\
							sizeof(struct calc)))
				return -EFAULT;
			printk(KERN_ALERT "\n Kernel :: Div . \n");
			return 0;
		}
		default:
			return -EINVAL;
	}
}

static int sample_open(struct inode *inode, struct file *filp)
{
	printk(KERN_ALERT "\n sample_open called \n");
	return 0;
}

static int  sample_close(struct inode *inode, struct file *filp)
{
	printk(KERN_ALERT "\n sample_close called \n");
	return 0;
}

module_init(ourinitmodule);
module_exit(ourcleanupmodule);
