obj-m += moduleone.o
obj-m += moduletwo.o

all:
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) modules
	sudo cp *.ko /lib/modules/$(shell uname -r)/
	sudo depmod -a

clean: 
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) clean
	sudo rm  /lib/modules/$(shell uname -r)/moduleone.ko
	sudo rm  /lib/modules/$(shell uname -r)/moduletwo.ko
	sudo depmod -a
