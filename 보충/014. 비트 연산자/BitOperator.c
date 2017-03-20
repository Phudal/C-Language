#include <stdio.h>

int main()
{
	char cNum1 = 4; // 00000100
	char cNum2 = 8; // 00001000

	// & ������ => �ϳ��� 0�̸� 0
	cNum1 &= cNum2;
	printf("& ���� ��� : %d\n\n", cNum1);
	cNum1 = 4;

	// | ������ => �ϳ��� 1�̸� 1
	cNum1 |= cNum2;
	printf("| ���� ��� : %d\n\n", cNum1);
	cNum1 = 4;
	
	// ^ ������ => �� �� ������ 0 �ٸ��� 1
	cNum1 ^= cNum2;
	printf("^ ���� ��� : %d\n\n", cNum1);
	cNum1 = 4;

	// << => �������� ��Ʈ �̵�(�� 2�� ����)
	cNum1 <<= 1;
	printf("^ ���� ��� : %d\n\n", cNum1);
	cNum1 = 4;

	// >> => ���������� ��Ʈ �̵�(�� 2�� ����)
	cNum1 >>= 1;
	printf("^ ���� ��� : %d\n\n", cNum1);
	cNum1 = 4;
	return 0;
}