#include <stdio.h>

typedef struct tagBitFlag
{
	unsigned char iFlagOutput : 1;
	unsigned char iFlagInput  : 1;
	unsigned char iFlagAdd    : 1;
	unsigned char iFlagSub    : 1;
	unsigned char iFlagAlarm  : 1;
	unsigned char             : 3;
}BITFLAG;

void BitFlagCheck(const char cCurrentFlag, BITFLAG tBitFlag)
{
	int iNum1, iNum2;

	if (cCurrentFlag & tBitFlag.iFlagOutput)
	{
		puts("iFlagOutput�� �۵��˴ϴ�.");
		puts("��Ʈ �ʵ� ����ü�� �˾ƺ��� ���Դϴ�.");
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagInput)
	{
		puts("iFlagInput�� �۵��˴ϴ�.");
		printf("���� �ϳ��� �Է��ϼ��� : ");
		scanf("%d", &iNum1);
		printf("�Է��� ���ڴ� %d�Դϴ�.\n", iNum1);
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagAdd)
	{
		puts("iFlagAdd�� �۵��˴ϴ�.");
		printf("���� �ΰ��� �Է��ϼ��� : ");
		scanf("%d %d", &iNum1, &iNum2);
		printf("%d + %d = %d�Դϴ�.\n", iNum1, iNum2, iNum1 + iNum2);
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagSub)
	{
		puts("iFlagSub�� �۵��˴ϴ�.");
		printf("���� �ΰ��� �Է��ϼ��� : ");
		scanf("%d %d", &iNum1, &iNum2);
		printf("%d - %d = %d�Դϴ�.\n", iNum1, iNum2, iNum1 + iNum2);
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagAlarm)
	{
		puts("iFlagAlarm�� �۵��˴ϴ�.");
		puts("�˶� �۵� ����! \a");
		puts("------------------------------------");
	}
}

int main()      
{
	char cCurrentFlag;
	BITFLAG tBitFlag = {1, 1, 1, 1, 1};
	printf("BITFLAG�� ũ�� : %d����Ʈ\n\n", sizeof(BITFLAG));

	cCurrentFlag = tBitFlag.iFlagOutput | tBitFlag.iFlagInput |
		tBitFlag.iFlagAdd | tBitFlag.iFlagSub | tBitFlag.iFlagAlarm;
	BitFlagCheck(cCurrentFlag, tBitFlag);
	return 0;
}