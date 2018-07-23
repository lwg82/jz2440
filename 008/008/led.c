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


int led_on(int which)
{
	unsigned int *pGPFCON =  (unsigned int *)0x56000050;
	unsigned int *pGPFDATA = (unsigned int *)0x56000054;

	if(4 == which)
	{
		/* 配置 GPF4 为输出引脚 */
		*pGPFCON = 0x100;
	}
	else if(5 == which)
	{
		/* 配置 GPF5 为输出引脚 */
		*pGPFCON = 0x400;
	}

	/* 设置GPF4输出0 */
	*pGPFDATA = 0;

}





