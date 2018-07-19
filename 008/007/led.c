

void main()
{
	unsigned int *pGPFCON =  (unsigned int *)0x56000050;
	unsigned int *pGPFDATA = (unsigned int *)0x56000054;

	/* 配置 GPF4 为配置引脚 */
	*pGPFCON = 0x100;

	/* 设置GPF4输出0 */
	*pGPFDATA = 0;
}





