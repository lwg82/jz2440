

.text
.global _start


_start:

	/* 关闭看门口 */
	LDR  r0, =0x53000000;
	LDR  r1, =0;
	STR  r1, [r0];

	/* 分辨是 nand or nor 启动
	 * 写0到0地址, 再读出来
	 * 如果得到0, 表示0地址上的内容被修改了, 它对应ram, 这就是nand启动
	 * 否则就是nor启动
	*/
	MOV   r1, #0;
	LDR   r0, [r1];   // 读出原来的值，用于备份
	STR   r1, [r1]
	LDR   r2, [r1]
	cmp   r1, r2
    ldr   sp, =0x40000000+4096   // 假设是nor启动
	moveq sp, #4096      //  nand 启动
	streq r0, [r1]        /* 恢复原来的值 */
	
	
	bl  main

	
	
halt:
	b halt







