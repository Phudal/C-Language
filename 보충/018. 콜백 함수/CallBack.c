#include <stdio.h>

// ������ ��� ���Ϸ� �־�� ��
extern int  EnrollFunc(void(* EnrollFunc)());
extern void StartFunc(const int iFuncCnt);

// ��� ���� �� ���� �Լ� ����ϱ�
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
	puts("-------1�� �ݹ� �Լ� ȣ��-------");
	iResult = EnrollFunc(PrintHelloWorld);
	StartFunc(iResult);

	puts("-------2�� �ݹ� �Լ� ȣ��-------");
	StartFunc(EnrollFunc(PrintCallBack));
	
	puts("-------3�� �ݹ� �Լ� ȣ��-------");
	StartFunc(EnrollFunc(PrintEnd));
	return 0;
}