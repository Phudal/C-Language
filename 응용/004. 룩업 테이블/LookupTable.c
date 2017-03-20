#include <stdio.h>

typedef int(* PINT_DOUBLEINT)(int, int); // �Լ� ������ ������

int IntAdd(int iNum1, int iNum2)
{
	return iNum1 + iNum2;
}

int IntSub(int iNum1, int iNum2)
{
	return iNum1 - iNum2;
}

int IntMul(int iNum1, int iNum2)
{
	return iNum1 * iNum2;
}

int IntDiv(int iNum1, int iNum2)
{
	return iNum1 / iNum2;
}

int IntMod(int iNum1, int iNum2)
{
	return iNum1 % iNum2;
}

int main()
{
	int iInput;
	int iNum1, iNum2;
	PINT_DOUBLEINT pCalcFunc[5] = {IntAdd, IntSub, IntMul, IntDiv, IntMod};

	puts("������ ���� ���α׷��Դϴ�.");
	puts("<1. ����> <2. ����> <3. ����> <4. ������> <5. ������>\n");

	printf("���ϴ� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &iInput);

	if (iInput < 1 || iInput > 5)
	{
		puts("�߸��� ��ȣ�� �Է��߽��ϴ�!");
		return 0;
	}

	printf("�ƹ� ���� 2���� �Է��ϼ��� : ");
	scanf("%d %d", &iNum1, &iNum2);
	puts("------------------------------");
	printf("��� ����� %d�Դϴ�.\n", pCalcFunc[iInput - 1](iNum1, iNum2));
	return 0;
}
