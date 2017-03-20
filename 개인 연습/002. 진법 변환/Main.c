#include <stdio.h>
#include <stdlib.h>

#define STOP system("pause")

//void DecimalToBinary(int iDecimal, int Binary[32]);
//void PrintBinary(int Binary[32]);
int BinaryToDecimal(int Binary[8]);

void main(void)
{
	int i;
	int Binary[8] = {0, 0, 0, 1, 0, 0, 0, 1};

	printf("2���� : ");
	for (i = 0; i < 8; ++i)
	{
		printf("%d", Binary[i]);
	}

	printf("\n��ȯ�� �� : %d\n", BinaryToDecimal(Binary));

	//int Binary[32] = {0};
	//printf("10������ �Է��ϼ��� : "); scanf("%d", &iDecimal);
	//DecimalToBinary(iDecimal, Binary);
	//PrintBinary(Binary);

	STOP;
}

int BinaryToDecimal(int Binary[8])
{
	int i;
	int iPos = 1;
	int iDecimal = 0;
	
	for (i = 7; i >= 0; --i)
	{
		//printf("\n%d\n\n", Binary[i]);
		if (Binary[i])
		{
			//printf("\n%d\n", 2 << i);
			iDecimal += Binary[i] * iPos;
		}

		iPos = iPos << 1; // �ڸ��� ����
	}

	return iDecimal;
}

void DecimalToBinary(int iDecimal, int Binary[32])
{
	int iTemp = iDecimal;
	int iIdx = 0;

	while(iTemp != 0)
	{
		Binary[iIdx] = iTemp % 2; // 2�� ���� ������
		iTemp /= 2;
		iIdx++;
	}
}

void PrintBinary(int Binary[32])
{
	int i;
	int iCnt = 0;
	for (i = 31; i >= 0; --i)
	{
		if (iCnt == 8)
		{
			printf(" ");
			iCnt = 0;
		}

		printf("%d", Binary[i]);
		iCnt++;
	}

	printf("\n");
}