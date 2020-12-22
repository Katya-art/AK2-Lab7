ccflags-y := -I$(PWD)/inc
ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m   := hello1.o hello2.o
ccflags-y += -g
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD
	cp hello2.ko hello2.ko.unstripped
	$(CROSS_COMPILE)strip -g hello1.ko
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
%.s %.i: %.c
	$(MAKE) -C $(KDIR) M=$$PWD $@
endif
