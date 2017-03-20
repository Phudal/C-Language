#include <stdio.h>

int main()
{
	int i = 0; // 초깃값
	int iNum = 10;

	do 
	{
		iNum += 10; // 반복할 소스 코드
		++i;        // 증감식
	} while (i == 8); // 조건
	printf("iNum : %d\n", iNum);
	return 0;
}