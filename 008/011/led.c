/*
	ADD r0, r1, r2;   r0=r1+r2
	SUB r0, r1, #4;   r0=r1-4

	BL    branch and link;   跳转到xxx,并且把返回地址保存在 lr 寄存器

	LDM   读内存，写入多个寄存器

	STM   把多个寄存器的值写入内存

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
	
	/* 设置GPFCON让GPF4/5/6配置为输出引脚 */
	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));   // 清零 
	GPFCON |=   ((1<<8) | (1<<10) | (1<<12));

	/* 配置3个按键引脚为输入引脚:
		 * GPF0(S2),GPF2(S3),GPG3(S4)
		 */
	GPFCON &= ~((3<<0) | (3<<4));
	GPFCON &= ~((3<<6));  // gpg3

	while(1)
	{
		val1 = GPFDAT;
		val2 = GPGDAT;

		if(val1 & (1<<0))
		{   // 松开
			GPFDAT |= (1<<6); // 输出高电平
		}
		else
		{   // 按下
			GPFDAT &= ~(1<<6); // 输出低电平
		}


		if(val1 & (1<<2))
		{   // 松开
			GPFDAT |= (1<<5); // 输出高电平
		}
		else
		{   // 按下
			GPFDAT &= ~(1<<5); // 输出低电平
		}

		if(val2 & (1<<3))
		{   // 松开
			GPFDAT |= (1<<4); // 输出高电平
		}
		else
		{   // 按下
			GPFDAT &= ~(1<<4); // 输出低电平
		}
		
	}
}





