#include <stdio.h>

typedef int(* PINT_DOUBLEINT)(int, int); // 함수 포인터 재정의

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

	puts("간단한 계산기 프로그램입니다.");
	puts("<1. 덧셈> <2. 뺄셈> <3. 곱셈> <4. 나눗셈> <5. 나머지>\n");

	printf("원하는 번호를 입력하세요 : ");
	scanf("%d", &iInput);

	if (iInput < 1 || iInput > 5)
	{
		puts("잘못된 번호를 입력했습니다!");
		return 0;
	}

	printf("아무 숫자 2개를 입력하세요 : ");
	scanf("%d %d", &iNum1, &iNum2);
	puts("------------------------------");
	printf("계산 결과는 %d입니다.\n", pCalcFunc[iInput - 1](iNum1, iNum2));
	return 0;
}
