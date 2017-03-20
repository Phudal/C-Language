#include <stdio.h>
#include <stdlib.h>

int* DecimalToBinary(int iDecimal);
int BinaryToDecimal(int* pBinary);
void PrintBinary(int* pBinary);

#define MINUS 1
#define PLUS  0

int main()
{
	int* pBinary;

	pBinary = DecimalToBinary(-10);
	printf("10���� %d�� 2������ �ٲ� ��\n", -10);
	PrintBinary(pBinary);

	puts("------------------------------------");
	printf("2������ 10������ �ٲ� �� : %d\n", BinaryToDecimal(pBinary));
	free(pBinary);
	return 0;
}


int* DecimalToBinary(int iDecimal)
{
	int i;
	int iSign = PLUS;
	int* pBinary = (int*)malloc(sizeof(int) * 32);

	if (iDecimal < 0)
	{
		iSign = MINUS;
		iDecimal *= -1;
	}

	for (i = 0; i < 32; ++i)
	{
		pBinary[i] = iDecimal % 2;
		iDecimal >>= 1;
	}

	// 10������ �������
	if (iSign == MINUS)
	{
		for (i = 0; i < 32; ++i)
		{
			(pBinary[i] == 0) ? (pBinary[i] = 1) : (pBinary[i] = 0);
		}

		pBinary[0] += 1; // 1�� ���� + 1

		// �ֻ��� ��Ʈ�� ��ȣ ��Ʈ�̹Ƿ� �˻� ����
		for (i = 0; i < 32 - 1; ++i)
		{
			if (pBinary[i] == 2)
			{
				pBinary[i] = 0;
				pBinary[i + 1] += 1;
			}
			else
			{
				break;
			}
		}
	}
	return pBinary;
}

int BinaryToDecimal(int* pBinary)
{
	int i;
	int iTemp = 1;
	int iDecimal = 0;

	for (i = 32 - 1; i >= 0; --i)
	{
		// signed int�� �ٲٹǷ� ��ȣ�� �Ű� �� �ʿ� ����
		if (pBinary[i] == 1)
		{
			iTemp <<= i;
			iDecimal += iTemp;
			iTemp = 1;
		}
	}
	return iDecimal;
}

void PrintBinary(int* pBinary)
{
	int i;
	for (i = 32 - 1; i >= 0; --i)
	{
		printf("%d", pBinary[i]);
		if (i % 8 == 0)
		{
			printf(" ");
		}
	}
	puts("");
}

