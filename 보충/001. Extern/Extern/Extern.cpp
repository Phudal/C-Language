// Extern.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Add.h"

int g_iNum; // extern 사용

int _tmain(int argc, _TCHAR* argv[])
{
	printf("extern 사용 전의 값 : %d\n", g_iNum);
	AddNum();
	printf("extern 사용 후의 값 : %d\n", g_iNum);
	return 0;
}

