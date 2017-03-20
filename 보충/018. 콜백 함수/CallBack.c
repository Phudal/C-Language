#include <stdio.h>

// 원래는 헤더 파일로 넣어야 됨
extern int  EnrollFunc(void(* EnrollFunc)());
extern void StartFunc(const int iFuncCnt);

// 헤더 파일 안 쓰고 함수 사용하기
void PrintHelloWorld()
{
	puts("Hello World");
}

void PrintCallBack()
{
	puts("CallBack");
}

void PrintEnd()
{
	puts("End");
}

int main()
{
	int iResult;
	puts("-------1차 콜백 함수 호출-------");
	iResult = EnrollFunc(PrintHelloWorld);
	StartFunc(iResult);

	puts("-------2차 콜백 함수 호출-------");
	StartFunc(EnrollFunc(PrintCallBack));
	
	puts("-------3차 콜백 함수 호출-------");
	StartFunc(EnrollFunc(PrintEnd));
	return 0;
}