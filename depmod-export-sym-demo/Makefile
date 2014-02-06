obj-m += jayone.o
obj-m += jaytwo.o

all:
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) modules
	sudo cp *.ko /lib/modules/$(shell uname -r)/
	sudo depmod -a

clean: 
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) clean
	sudo rm  /lib/modules/$(shell uname -r)/jayone.ko
	sudo rm  /lib/modules/$(shell uname -r)/jaytwo.ko
	sudo depmod -a
