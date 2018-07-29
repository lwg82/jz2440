/*
	ADD r0, r1, r2;   r0=r1+r2
	SUB r0, r1, #4;   r0=r1-4

	BL    branch and link;   ��ת��xxx,���Ұѷ��ص�ַ������ lr �Ĵ���

	LDM   ���ڴ棬д�����Ĵ���

	STM   �Ѷ���Ĵ�����ֵд���ڴ�

	LDMIA

	STMDB

*/
#include "s3c2440_soc.h"


void delay(volatile int d)
{
	while (d--);
}


int main()
{
	volatile int val = 0;
	volatile int tmp = 0;

	
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));   // ���� 
	GPFCON |=  ((1<<8) | (1<<10) | (1<<12));
	
	while(1)
	{
		tmp = ~val;
		tmp &= 7;


		GPFDAT &= ~(7<<4);
		GPFDAT |= (tmp << 4);

		delay(100000);

		val++;

		if(val == 8)
			val = 0;
	}
	
	return 0;
}





