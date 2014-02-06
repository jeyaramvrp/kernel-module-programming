#include <linux/module.h>
#include <linux/kernel.h>

#include "CommonHeader.h"

MODULE_LICENSE("GPL");

int __init ourinitmodule(void)
{
	printk(KERN_ALERT "\n sample -2 init.... \n");
	/* Making two.c to depend on one.c */
	sample1func();
	return 0;
}

void __exit ourcleanupmodule(void)
{
	printk(KERN_ALERT "\n sample -2 Exit.... \n");
}

module_init(ourinitmodule);
module_exit(ourcleanupmodule);
