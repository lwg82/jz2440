

.text
.global _start


_start:

	/* 关闭看门口 */
	LDR  r0, =0x53000000;
	LDR  r1, =0;
	str  r1, [r0];

	/* 设置MPLL, FCLK:HCLK:PCLK=400M:100M:50M*/
	
	/*
		LOCKTIME(0x4C000000)=0xFFFFFFFF
	*/
	LDR r0, =0x4C000000
	LDR r1, =0xFFFFFFFF
	STR r1, [r0]
	
	/*
		CLKDIVN(0x4C000014)=0x5, tFCLK:tHCLK:tPCLK=1:4:8
	*/
	LDR r0, =0x4C000014
	LDR r1, =0x5
	STR r1, [r0]

	/*
		设置CPU工作于异步模式
	*/
	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xc0000000
	mcr p15,0,r0,c1,c0,0

	/*
		设置 MPLLCON(0x4C000004)= (92<<12)|(1<<4)|(1<<0)
		m = MDIV+8 = 92+8 = 100
		p = PDIV +2 = 1+2 =3
		s = SDIV = 1
		FLCK = 2*m*Fin/(p*2^s)= 2*100*12/(3*2^1)=400M		
	*/
	LDR r0, =0x4C000004
	LDR r1, =(92<<12)|(1<<4)|(1<<0)
	STR r1, [r0]

	/* 一旦设置PLL, 就会锁定lock time直到PLL输出稳定
	 * 然后CPU工作于新的频率FCLK
	 */

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







