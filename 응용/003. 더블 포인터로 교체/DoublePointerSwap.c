#include <stdio.h>
#include <conio.h>

void DoublePointerSwap(int** ppNum1, int** ppNum2)
{
	int* pTemp = *ppNum1;
	*ppNum1    = *ppNum2;
	*ppNum2    = pTemp;
}

int main()
{
	int iNum1 = 100, iNum2 = 200;
	int* pNum1 = &iNum1;
	int* pNum2 = &iNum2;
	printf("값을 바꾸기 전의 iNum1의 값 : %d\n", *pNum1);
	printf("값을 바꾸기 전의 iNum2의 값 : %d\n\n", *pNum2);
	DoublePointerSwap(&pNum1, &pNum2);
	printf("값을 바꾸기 전의 iNum1의 값 : %d\n", *pNum1);
	printf("값을 바꾸기 전의 iNum2의 값 : %d\n", *pNum2);
	_getch();
	return 0;
}