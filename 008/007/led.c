/*
	ADD r0, r1, r2;   r0=r1+r2
	SUB r0, r1, #4;   r0=r1-4

	BL    branch and link;   跳转到xxx,并且把返回地址保存在 lr 寄存器

	LDM   读内存，写入多个寄存器

	STM   把多个寄存器的值写入内存

	LDMIA

	STMDB

*/

void main()
{
	unsigned int *pGPFCON =  (unsigned int *)0x56000050;
	unsigned int *pGPFDATA = (unsigned int *)0x56000054;

	/* 配置 GPF4 为配置引脚 */
	*pGPFCON = 0x100;

	/* 设置GPF4输出0 */
	*pGPFDATA = 0;
}





