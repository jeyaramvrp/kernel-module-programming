#include <linux/module.h>
#include <linux/kernel.h>

#include "CommonHeader.h"

MODULE_LICENSE("GPL");

int __init ourinitmodule(void)
{
	printk(KERN_ALERT "\n sample -1 init.... \n");
	return 0;
}

void __exit ourcleanupmodule(void)
{
	printk(KERN_ALERT "\n sample -1 Exit.... \n");
}

int sample1func()
{
	printk(KERN_ALERT "\n sample -1 Exported Function .... \n");
	return 0;
}
EXPORT_SYMBOL(sample1func);

module_init(ourinitmodule);
module_exit(ourcleanupmodule);
