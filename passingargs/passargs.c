#include <linux/module.h>
#include <linux/kernel.h>
/* Added for module_param */
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

/* Module param : Integer data */
static int data;
module_param(data, int, S_IRUSR|S_IWUSR);

/* Module param : String data */
static char *mystr = "Default";
module_param(mystr, charp, 0);

/* Module param : Integer Array data */
static int myarray[10] = {-1};
static int count = 0;
module_param_array(myarray, int,&count, 0);

int ourinitmodule(void)
{
	int tmp = 0;

	/* Print data - Default values will be printed if No argument is passed. */
	printk(KERN_ALERT "\n Demo for Passing arguments to kernel module \n");
	printk(KERN_ALERT "\n data:%d\n", data);
	printk(KERN_ALERT "\n mystr:%s\n", mystr);

	for(tmp = 0; tmp < count ; tmp++)	
	printk(KERN_ALERT "\n myarray[%d]:%d", tmp, myarray[tmp]);
	
	return 0;
}

void ourcleanupmodule(void)
{
	printk(KERN_ALERT "\n Thanks....Exiting Passing args sample.. \n");
}

module_init(ourinitmodule);
module_exit(ourcleanupmodule);
