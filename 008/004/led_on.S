/*
 点亮LED2: GPF5

汇编指令
LDR  R0,[R1]   读内存,从右到左
STR  R0, [R1]  写内存命令, 从左到右
B    跳转指令
MOV   移动
LDR  R0, =0x12345678  伪指令


1 配置 GPF4 为输出引脚：把 0x100 写入地址 0x5600 0050
2 设置 GPF4 输出高电平: 把 0x10  写入地址 0x5600 0054

编译命令
arm-linux-gcc      -c -o led_on.o led_on.S
arm-linux-ld       -Ttext 0 led_on.o -o led_on.elf
arm-linux-objcopy  -O binary -S led_on.elf led_on.bin   # O,S大写


R13     sp	    Stack Pointer   
R14     lr      Link Register
R15     pc      Program lounter = 当前指令 + 8;  流水线： 当前执行地址A的指令,已经在对A+4的指令进行译码，已经在读取地址A+8的指令， pc=A+8

*/



.text

.global _start


_start:

	// 配置 GPF5 为输出引脚：把 0x400 写入地址 0x5600 0050

	LDR r1, =0x56000050
	MOV r0, #0x400
	STR r0, [r1]


	
	// 设置 GPF5 输出高电平: 把 0x10  写入地址 0x5600 0054

	LDR r1, =0x56000054
	LDR r0, =0          
	STR r0, [r1]


	// 死循环
halt:
	B halt
		
