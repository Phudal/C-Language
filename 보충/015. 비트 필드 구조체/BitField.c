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
		puts("iFlagOutput이 작동됩니다.");
		puts("비트 필드 구조체를 알아보는 중입니다.");
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagInput)
	{
		puts("iFlagInput이 작동됩니다.");
		printf("숫자 하나를 입력하세요 : ");
		scanf("%d", &iNum1);
		printf("입력한 숫자는 %d입니다.\n", iNum1);
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagAdd)
	{
		puts("iFlagAdd가 작동됩니다.");
		printf("숫자 두개를 입력하세요 : ");
		scanf("%d %d", &iNum1, &iNum2);
		printf("%d + %d = %d입니다.\n", iNum1, iNum2, iNum1 + iNum2);
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagSub)
	{
		puts("iFlagSub이 작동됩니다.");
		printf("숫자 두개를 입력하세요 : ");
		scanf("%d %d", &iNum1, &iNum2);
		printf("%d - %d = %d입니다.\n", iNum1, iNum2, iNum1 + iNum2);
		puts("------------------------------------");
	}

	if (cCurrentFlag & tBitFlag.iFlagAlarm)
	{
		puts("iFlagAlarm이 작동됩니다.");
		puts("알람 작동 개시! \a");
		puts("------------------------------------");
	}
}

int main()      
{
	char cCurrentFlag;
	BITFLAG tBitFlag = {1, 1, 1, 1, 1};
	printf("BITFLAG의 크기 : %d바이트\n\n", sizeof(BITFLAG));

	cCurrentFlag = tBitFlag.iFlagOutput | tBitFlag.iFlagInput |
		tBitFlag.iFlagAdd | tBitFlag.iFlagSub | tBitFlag.iFlagAlarm;
	BitFlagCheck(cCurrentFlag, tBitFlag);
	return 0;
}