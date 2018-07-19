

.text
.global _start


_start:

	/* 设置内存: sp 栈 */
	LDR   sp,  =4096   /* nand 启动 */
	//LDR   sp,  =0x40000000 + 4096   /* nor 启动*/

	/* 调用 main */
	bl  main     // 跳转到 main 执行，并且保存返回地址


halt:
	b halt







