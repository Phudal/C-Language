void InputData3DArray(wchar_t Array3D[][LINE][SENTENCE], const FILE* pFile)
{
	int i, j;

	printf("�ִ� �� : %d | �ִ� �� : %d\n", LINE, PAGE);
	puts("������ �Է��ϼ���.\n");

	for (i = 0; i < PAGE; ++i)
	{
		for (j = 0; j < LINE; ++j)
		{
			_getws(Array3D[i][j], SENTENCE);
			fwprintf(pFile, L"%s\n", Array3D[i][j]);
		}

		fwprintf(pFile, L"%s %d�� %s\n", BOUND, i + 1, BOUND);
		wprintf(L"������� %d�� �Է�\n\n", i + 1);
	}
}

void InputData2DArrayPointer(wchar_t(*pArray2D)[LINE][SENTENCE], const FILE* pFile)
{
	int i, j;

	printf("�ִ� �� : %d | �ִ� �� : %d\n", LINE, PAGE);
	puts("������ �Է��ϼ���.\n");

	for (i = 0; i < PAGE; ++i)
	{
		for (j = 0; j < LINE; ++j)
		{
			_getws(pArray2D[i][j], SENTENCE);
			fwprintf(pFile, L"%s\n", pArray2D[i][j]);
		}

		fwprintf(pFile, L"%s %d�� %s\n", BOUND, i + 1, BOUND);
		wprintf(L"������� %d�� �Է�\n\n", i + 1);
	}
}

void PrintData(wchar_t pArray3D[][LINE][SENTENCE], const FILE* pFile)
{
	int i, j;

	_putws(L"---------------------------------------------------");
	_putws(L"�Էµ� ������ ���� �� ����մϴ�.\n");

	for (i = 0; i < PAGE; ++i)
	{
		for (j = 0; j < LINE; ++j)
		{
			wprintf(L"%s\n", pArray3D[i][j]);
		}
		wprintf(L"%s %d�� %s\n", BOUND, i + 1, BOUND);
	}
}