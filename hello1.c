#include "hello1.h"

static LIST_HEAD(my_list);

void print_hello(uint n){
	uint i;
	struct data *item;
	struct data *md, *tmp;
	for(i = 0; i < n; i++){
		if (i != 5){
			item = kmalloc(sizeof(struct data), GFP_KERNEL);
		}else {
			item = 0;
		}
		if (ZERO_OR_NULL_PTR(item))
			goto no_memory;
		item->begin_time = ktime_get();
		pr_info("Hello, world!\n");
		item->end_time = ktime_get();
		list_add_tail(&(item->next), &my_list);
	}
	return 0;

no_memory:
	list_for_each_entry_safe(md, tmp, &my_list, next) {
		list_del(&md->next);
		kfree(md);
	}
	BUG_ON("Not enough memory");
	return -1;
}

EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void){
	pr_info("hello1 is inited\n");
	return 0;
}

static void __exit hello1_exit(void){
	struct data *md, *tmp;
	list_for_each_entry_safe(md, tmp, &my_list, next) {
		pr_info("Time: %lli\n", md->end_time - md->begin_time);
		list_del(&md->next);
		kfree(md);
	}
}

module_init(hello1_init);
module_exit(hello1_exit);
