#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int __init ourinitmodule(void)
{
	printk(KERN_ALERT "\n Welcome to sample application.... \n");
	return 0;
}

void __exit ourcleanupmodule(void)
{
	printk(KERN_ALERT "\n Thanks....Exiting Application. \n");
}

module_init(ourinitmodule);
module_exit(ourcleanupmodule);
