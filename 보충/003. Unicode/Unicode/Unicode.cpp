// Unicode.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	wchar_t  wszName1[100];
	wchar_t  wszName2[100];
	wchar_t* wszName3 = L"㉴己Б했던기억들도〃ユェй란㈔乙占도♡";
	FILE* pFile = fopen("Unicode.txt", "wt");
	
	_wsetlocale(LC_ALL, L"Korean");

	_getws(wszName2);
	wcscpy(wszName1, _T("흑염룡이 내 안에서 솟구친다"));
	wcscat(wszName1, _T(" 내 생이 끝날 때까지!"));

	wprintf(L"%s\n",  argv[0]);
	wprintf(L"%ls\n", wszName1);
	wprintf(L"%ws\n", wszName2);
	wprintf(L"%ws\n", wszName3);

	// 파일 출력
	fwprintf(pFile, wszName1);
	fwprintf(pFile, L"\n");
	fwprintf(pFile, wszName2);
	fwprintf(pFile, L"\n");
	fwprintf(pFile, wszName3);
	fwprintf(pFile, L"\n");
	fclose(pFile);
	return 0;
}

