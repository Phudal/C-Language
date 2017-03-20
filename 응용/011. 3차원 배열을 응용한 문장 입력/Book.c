void InputData3DArray(wchar_t Array3D[][LINE][SENTENCE], const FILE* pFile)
{
	int i, j;

	printf("최대 줄 : %d | 최대 쪽 : %d\n", LINE, PAGE);
	puts("문장을 입력하세요.\n");

	for (i = 0; i < PAGE; ++i)
	{
		for (j = 0; j < LINE; ++j)
		{
			_getws(Array3D[i][j], SENTENCE);
			fwprintf(pFile, L"%s\n", Array3D[i][j]);
		}

		fwprintf(pFile, L"%s %d쪽 %s\n", BOUND, i + 1, BOUND);
		wprintf(L"현재까지 %d쪽 입력\n\n", i + 1);
	}
}

void InputData2DArrayPointer(wchar_t(*pArray2D)[LINE][SENTENCE], const FILE* pFile)
{
	int i, j;

	printf("최대 줄 : %d | 최대 쪽 : %d\n", LINE, PAGE);
	puts("문장을 입력하세요.\n");

	for (i = 0; i < PAGE; ++i)
	{
		for (j = 0; j < LINE; ++j)
		{
			_getws(pArray2D[i][j], SENTENCE);
			fwprintf(pFile, L"%s\n", pArray2D[i][j]);
		}

		fwprintf(pFile, L"%s %d쪽 %s\n", BOUND, i + 1, BOUND);
		wprintf(L"현재까지 %d쪽 입력\n\n", i + 1);
	}
}

void PrintData(wchar_t pArray3D[][LINE][SENTENCE], const FILE* pFile)
{
	int i, j;

	_putws(L"---------------------------------------------------");
	_putws(L"입력된 내용을 전부 다 출력합니다.\n");

	for (i = 0; i < PAGE; ++i)
	{
		for (j = 0; j < LINE; ++j)
		{
			wprintf(L"%s\n", pArray3D[i][j]);
		}
		wprintf(L"%s %d쪽 %s\n", BOUND, i + 1, BOUND);
	}
}