// Unicode.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	wchar_t  wszName1[100];
	wchar_t  wszName2[100];
	wchar_t* wszName3 = L"�������ߴ����鵵���櫧�۶�����￵���";
	FILE* pFile = fopen("Unicode.txt", "wt");
	
	_wsetlocale(LC_ALL, L"Korean");

	_getws(wszName2);
	wcscpy(wszName1, _T("�濰���� �� �ȿ��� �ڱ�ģ��"));
	wcscat(wszName1, _T(" �� ���� ���� ������!"));

	wprintf(L"%s\n",  argv[0]);
	wprintf(L"%ls\n", wszName1);
	wprintf(L"%ws\n", wszName2);
	wprintf(L"%ws\n", wszName3);

	// ���� ���
	fwprintf(pFile, wszName1);
	fwprintf(pFile, L"\n");
	fwprintf(pFile, wszName2);
	fwprintf(pFile, L"\n");
	fwprintf(pFile, wszName3);
	fwprintf(pFile, L"\n");
	fclose(pFile);
	return 0;
}

