/*
	ADD r0, r1, r2;   r0=r1+r2
	SUB r0, r1, #4;   r0=r1-4

	BL    branch and link;   跳转到xxx,并且把返回地址保存在 lr 寄存器

	LDM   读内存，写入多个寄存器

	STM   把多个寄存器的值写入内存

	LDMIA

	STMDB

*/

void delay(volatile int d)
{
	while (d--);
}


int main()
{
	volatile unsigned int *pGPFCON =  (unsigned int *)0x56000050;
	volatile unsigned int *pGPFDATA = (unsigned int *)0x56000054;

	/* 设置GPFCON让GPF4/5/6配置为输出引脚 */
	*pGPFCON &= ~((3<<8) | (3<<10) | (3<<12));   // 清零 
	*pGPFCON |=  ((1<<8) | (1<<10) | (1<<12));

	// 循环点亮

	volatile int val = 0;
	volatile int tmp;
	
	while(1)
	{
		tmp = ~val;
		tmp &= 7;
	
		*pGPFDATA &= ~(7<<4);
		*pGPFDATA |= (tmp << 4);

		delay(100000);

		val++;

		if(val == 8)
			val = 0;
	}
}





