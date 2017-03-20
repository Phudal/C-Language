#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> // va_start, va_arg, va_end

int AddNum(int iCnt, ...)
{
	int i, iResult = 0;
	va_list ArgList;

	va_start(ArgList, iCnt);
	for (i = 0; i < iCnt; ++i)
	{
		iResult += va_arg(ArgList, int);
	}
	va_end(ArgList);
	return iResult;
};

int MyPrintf(const char* pFormat, ...)
{
	char* pBuffer;
	int iLength;

	va_list ArgList;
	va_start(ArgList, pFormat);

	// _vscprintf() => ���� ���ڸ� �Է¹ް� ���� ���ڸ� �����ϴ� ��� �Լ�
	iLength = _vscprintf(pFormat, ArgList) + 1;
	pBuffer = (char*)malloc(sizeof(char) * iLength);
	vsprintf_s(pBuffer, sizeof(char) * iLength, pFormat, ArgList);
	va_end(ArgList);

	iLength = strlen(pBuffer);
	printf(pBuffer);
	free(pBuffer);
	return iLength;
}

int main()
{
	//printf("��� �� : %d\n", AddNum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
	MyPrintf("��� �� : %d\n", AddNum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
	return 0;
}