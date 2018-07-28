

.text
.global _start


_start:
	
	


	/* 设置内存: sp 栈 */
	LDR   sp,  =4096   /* nand 启动 */
	//LDR   sp,  =0x40000000 + 4096   /* nor 启动*/

	mov r0, #4
	bl led_on    // 跳转到 led_on 执行，并且保存返回地址


	ldr r0, =100000
	bl delay

	mov r0, #5
	bl led_on

	
	
halt:
	b halt







