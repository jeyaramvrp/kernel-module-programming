#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/usb/hcd.h>
#include <linux/list.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");

int ourinitmodule(void)
{
	int chix = 0;
	struct usb_device *dev, *childdev = NULL;
	struct usb_bus *bus = NULL;

	list_for_each_entry(bus, &usb_bus_list, bus_list)
	{
		printk(KERN_ALERT "\n USB Bus : %d", bus->busnum);
		dev = bus->root_hub;
		printk(KERN_ALERT "\n Vendor Id:%x, Product Id:%x\n", \
			dev->descriptor.idVendor, dev->descriptor.idProduct);

		#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,7,0)
		usb_hub_for_each_child(dev, chix, childdev)
		{
			if(childdev)
			{
				printk("\n Vendor Id:%x, Product Id:%x\n",\
				childdev->descriptor.idVendor,\
				childdev->descriptor.idProduct);
			}
		}
		#endif
	}
	return 0;
}
void ourcleanupmodule(void)
{
	printk(KERN_ALERT "\n Thanks....Exiting USB Application. \n");
}
module_init(ourinitmodule);
module_exit(ourcleanupmodule);
