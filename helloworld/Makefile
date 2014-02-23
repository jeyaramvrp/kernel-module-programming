TARGET ?= hello

obj-m += $(TARGET).o

all:
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) modules
	@echo ""
	@echo "$(TARGET).ko Module created"

clean: 
	make -C /lib/modules/$(shell uname -r)/build  M=$(PWD) clean

load:
	sudo insmod $(PWD)/$(TARGET).ko
	@echo "$(TARGET) Module Loaded: check dmesg for details"

unload:
	sudo rmmod $(TARGET)
	@echo "$(TARGET) Module unloaded: check dmesg for details"
