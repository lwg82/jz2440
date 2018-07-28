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


int main()
{
	volatile unsigned int *pGPFCON =  (unsigned int *)0x56000050;
	volatile unsigned int *pGPFDATA = (unsigned int *)0x56000054;

	/* ����GPFCON��GPF4/5/6����Ϊ������� */
	*pGPFCON &= ~((3<<8) | (3<<10) | (3<<12));   // ���� 
	*pGPFCON |=  ((1<<8) | (1<<10) | (1<<12));

	// ѭ������

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





