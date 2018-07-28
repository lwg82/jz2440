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
	int val1, val2;
	
	/* ����GPFCON��GPF4/5/6����Ϊ������� */
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));   // ���� 
	GPFCON |=   ((1<<8) | (1<<10) | (1<<12));

	/* ����3����������Ϊ��������:
		 * GPF0(S2),GPF2(S3),GPG3(S4)
		 */
	GPFCON &= ~((3<<0) | (3<<4));
	GPFCON &= ~((3<<6));  // gpg3

	while(1)
	{
		val1 = GPFDAT;
		val2 = GPGDAT;

		if(val1 & (1<<0))
		{   // �ɿ�
			GPFDAT |= (1<<6); // ����ߵ�ƽ
		}
		else
		{   // ����
			GPFDAT &= ~(1<<6); // ����͵�ƽ
		}


		if(val1 & (1<<2))
		{   // �ɿ�
			GPFDAT |= (1<<5); // ����ߵ�ƽ
		}
		else
		{   // ����
			GPFDAT &= ~(1<<5); // ����͵�ƽ
		}

		if(val2 & (1<<3))
		{   // �ɿ�
			GPFDAT |= (1<<4); // ����ߵ�ƽ
		}
		else
		{   // ����
			GPFDAT &= ~(1<<4); // ����͵�ƽ
		}
		
	}
}





