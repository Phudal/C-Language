#include <stdio.h>

int main()
{
	char cNum1 = 4; // 00000100
	char cNum2 = 8; // 00001000

	// & 연산자 => 하나라도 0이면 0
	cNum1 &= cNum2;
	printf("& 연산 결과 : %d\n\n", cNum1);
	cNum1 = 4;

	// | 연산자 => 하나라도 1이면 1
	cNum1 |= cNum2;
	printf("| 연산 결과 : %d\n\n", cNum1);
	cNum1 = 4;
	
	// ^ 연산자 => 둘 다 같으면 0 다르면 1
	cNum1 ^= cNum2;
	printf("^ 연산 결과 : %d\n\n", cNum1);
	cNum1 = 4;

	// << => 왼쪽으로 비트 이동(값 2배 증가)
	cNum1 <<= 1;
	printf("^ 연산 결과 : %d\n\n", cNum1);
	cNum1 = 4;

	// >> => 오른쪽으로 비트 이동(값 2배 감소)
	cNum1 >>= 1;
	printf("^ 연산 결과 : %d\n\n", cNum1);
	cNum1 = 4;
	return 0;
}