/*
 ����LED2: GPF5

���ָ��
LDR  R0,[R1]   ���ڴ�,���ҵ���
STR  R0, [R1]  д�ڴ�����, ������
B    ��תָ��
MOV   �ƶ�
LDR  R0, =0x12345678  αָ��


1 ���� GPF4 Ϊ������ţ��� 0x100 д���ַ 0x5600 0050
2 ���� GPF4 ����ߵ�ƽ: �� 0x10  д���ַ 0x5600 0054

��������
arm-linux-gcc      -c -o led_on.o led_on.S
arm-linux-ld       -Ttext 0 led_on.o -o led_on.elf
arm-linux-objcopy  -O binary -S led_on.elf led_on.bin   # O,S��д


R13     sp	    Stack Pointer   
R14     lr      Link Register
R15     pc      Program lounter = ��ǰָ�� + 8;  ��ˮ�ߣ� ��ǰִ�е�ַA��ָ��,�Ѿ��ڶ�A+4��ָ��������룬�Ѿ��ڶ�ȡ��ַA+8��ָ� pc=A+8

*/



.text

.global _start


_start:

	// ���� GPF5 Ϊ������ţ��� 0x400 д���ַ 0x5600 0050

	LDR r1, =0x56000050
	MOV r0, #0x400
	STR r0, [r1]


	
	// ���� GPF5 ����ߵ�ƽ: �� 0x10  д���ַ 0x5600 0054

	LDR r1, =0x56000054
	LDR r0, =0          
	STR r0, [r1]


	// ��ѭ��
halt:
	B halt
		