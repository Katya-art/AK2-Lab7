#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/ktime.h>
#include <linux/slab.h>

MODULE_AUTHOR("Kateryna Kravchenko");
MODULE_DESCRIPTION("AK2_Lab5 advanced");
MODULE_LICENSE("Dual BSD/GPL");

extern void print_hello(uint n);

struct data {
	struct list_head next;
	ktime_t begin_time;
	ktime_t end_time;
};
