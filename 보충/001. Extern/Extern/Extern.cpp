// Extern.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Add.h"

int g_iNum; // extern ���

int _tmain(int argc, _TCHAR* argv[])
{
	printf("extern ��� ���� �� : %d\n", g_iNum);
	AddNum();
	printf("extern ��� ���� �� : %d\n", g_iNum);
	return 0;
}

