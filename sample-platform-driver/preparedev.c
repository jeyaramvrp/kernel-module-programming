#include <linux/module.h>
#include <linux/kernel.h>
//For platform drivers....
#include <linux/platform_device.h>

#include "platform-sample.h"

MODULE_LICENSE("GPL");

/* Specifying my resources information */
static struct resource sample_resources[] = {
        {
                .start          = RESOURCE1_START_ADDRESS,
                .end            = RESOURCE1_END_ADDRESS,
                .flags          = IORESOURCE_MEM,
        },
        {
                .start          = RESOURCE2_START_ADDRESS,
                .end            = RESOURCE2_END_ADDRESS,
                .flags          = IORESOURCE_MEM,
        },
	{
                .start          = SAMPLE_DEV_IRQNUM,
                .end            = SAMPLE_DEV_IRQNUM,
                .flags          = IORESOURCE_IRQ,
        }

	};


static struct platform_device sample_device = {
        .name           = DRIVER_NAME,
        .id             = -1,
        .num_resources  = ARRAY_SIZE(sample_resources),
        .resource       = sample_resources,
};

int ourinitmodule(void)
{
	printk(KERN_ALERT "\n Welcome to sample Platform driver(device).... \n");
	platform_device_register(&sample_device);
	return 0;
}

void ourcleanupmodule(void)
{
	platform_device_unregister(&sample_device);
	printk(KERN_ALERT "\n Thanks....Exiting sample Platform(device) driver... \n");
}

module_init(ourinitmodule);
module_exit(ourcleanupmodule);
