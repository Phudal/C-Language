#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Book.h"

int main()
{
	FILE* pFile;
	wchar_t Book[PAGE][LINE][SENTENCE] = {0};
	wchar_t(*pBook)[LINE][SENTENCE] = Book;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	pFile = _wfopen(L"Book.txt", L"wt");

	if (pFile == NULL)
	{
		_wperror(L"���� ��Ʈ�� ���� ����!");
		return 0;
	}

	InputData3DArray(Book, pFile);
	//InputData2DArrayPointer(pBook, pFile);

	_putws(L"������� �� ������ ���� ���Դϴ�...");
	_sleep(3000);

	PrintData(Book, pFile);
	fclose(pFile);
	return 0;
}
