#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
int flag = 1;

//Fake device
int tempdev = 0;

irqreturn_t sampleISR(int irq, void *dev_id)
{
	printk(KERN_ALERT "\n My ISR Called. \n");

	/* To allow actual device to handle it's interrupt. */
	return IRQ_NONE;		
}

int __init ourinitmodule(void)
{
	printk(KERN_ALERT "\n Welcome to sample application.... \n");

	if(request_irq(21, sampleISR, IRQF_SHARED, KBUILD_MODNAME, (void*)&tempdev))
	{
			printk("\n Error in isr registration. \n");
			flag = 0;	
	}
	return 0;
}

void __exit ourcleanupmodule(void)
{
	if(flag)
		free_irq(21, (void*)&tempdev);
	printk(KERN_ALERT "\n Thanks....Exiting Application. \n");
}

module_init(ourinitmodule);
module_exit(ourcleanupmodule);
