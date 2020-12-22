#include "hello1.h"

static uint n = 1;
module_param(n, uint, S_IRUGO);
MODULE_PARM_DESC(n, "Number must be in range [1, 10]");

static int __init hello_init(void){
	pr_info("Number=%d\n", n);

	if (n == 0){
		pr_warn("Better not to use 0\n");
	}else if (n >=5 && n <= 10) {
		pr_warn("It is better not to use a number greater than 5\n");
	}else if (n > 10){
		BUG_ON("N must be less then 10");
	}

	print_hello(n);

	return 0;
}

static void __exit hello_exit(void){
	//Do nothing here right now
}

module_init(hello_init);
module_exit(hello_exit);
