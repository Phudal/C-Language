#include <stdio.h>

int main()
{
	int iFlag; // 짝수 홀수를 판단하는 변수
	int iInput;

	printf("숫자 하나를 입력하세요 : ");
	scanf("%d", &iInput);

	// 삼항 조건 연산자에서는 연산 구문에 괄호가 필수!
	(iInput % 2 == 0) ? 
		((iFlag = 0) ? 
			((iFlag = 1) ? (iFlag = 5) : (iFlag = 6))
			: 
			((iFlag = 2) ? (iFlag = 7) : (iFlag = 8)))
		: 
		((iFlag = 1) ? 
			((iFlag = 3) ? (iFlag = 9) : (iFlag = 10))
			: 
			((iFlag = 4) ? (iFlag = 11) : (iFlag = 12)));
	printf("iFlag의 값 : %d\n", iFlag);
	return 0;
}