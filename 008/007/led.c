

void main()
{
	unsigned int *pGPFCON =  (unsigned int *)0x56000050;
	unsigned int *pGPFDATA = (unsigned int *)0x56000054;

	/* ���� GPF4 Ϊ�������� */
	*pGPFCON = 0x100;

	/* ����GPF4���0 */
	*pGPFDATA = 0;
}





