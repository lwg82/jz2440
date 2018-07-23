/*
	ADD r0, r1, r2;   r0=r1+r2
	SUB r0, r1, #4;   r0=r1-4

	BL    branch and link;   ��ת��xxx,���Ұѷ��ص�ַ������ lr �Ĵ���

	LDM   ���ڴ棬д�����Ĵ���

	STM   �Ѷ���Ĵ�����ֵд���ڴ�

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
		/* ���� GPF4 Ϊ������� */
		*pGPFCON = 0x100;
	}
	else if(5 == which)
	{
		/* ���� GPF5 Ϊ������� */
		*pGPFCON = 0x400;
	}

	/* ����GPF4���0 */
	*pGPFDATA = 0;

}





