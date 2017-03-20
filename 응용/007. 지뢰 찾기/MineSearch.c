// �⺻ ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// ���� ���� ��� ����
#include "Constant.h"

int InputBoardInfo(int* _iInputRow, int* _iInputCol)
{
	// ������� �Է��� ��� => ���ο� ���� ������ ����
	printf("�������� ���ο� ������ ũ�⸦ �������ּ��� : ");
	scanf("%d %d", _iInputCol, _iInputRow);

	if ((*_iInputRow) < 3 || (*_iInputRow) > 10 || (*_iInputCol) < 3 || (*_iInputCol) > 10)
	{
		puts("ũ�� ������ 3���� 10������ �����մϴ�.");
		return REUTRN_FAIL;
	}
	printf("������ ũ�⸦ %d, ������ ũ�⸦ %d�� �����߽��ϴ�.\n", *_iInputCol, *_iInputRow);
	puts("------------------------------------------------");
	return RETURN_SUCCESS;
}

int MallocBoard(char*** pppMineBoard, int _iInputRow, int _iInputCol)
{
	int iBoardRow;
	*pppMineBoard = (char**)malloc(sizeof(char*) * _iInputRow);

	if (*pppMineBoard == NULL)
	{
		puts("���θ� ���� �Ҵ����� ���߽��ϴ�.");
		return REUTRN_FAIL;
	}

	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		(*pppMineBoard)[iBoardRow] = (char*)malloc((sizeof(char) * _iInputCol) + 1);

		if ((*pppMineBoard)[iBoardRow] == NULL)
		{
			puts("���θ� ���� �Ҵ����� ���߽��ϴ�.");
			return REUTRN_FAIL;
		}

		memset((*pppMineBoard)[iBoardRow], 0, sizeof(char) * _iInputCol + 1);
	}
	return RETURN_SUCCESS;
}

void FreeBoard(char*** pppMineBoard, int _iInputRow)
{
	int iBoardRow;
	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		free((*pppMineBoard)[iBoardRow]);
	}
	free(*pppMineBoard);
}

void InputObject(char*** pppMineBoard, int _iInputRow)
{
	int iBoardRow;

	puts("���� ��ġ�� ���ּ���.");
	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		scanf("%s", (*pppMineBoard)[iBoardRow]);
	}
	puts("���� ��ġ�� �Ϸ��߽��ϴ�.");
	puts("------------------------------------------------");
}

void SearchMine(char*** pppMineBoard, int _iInputRow, int _iInputCol)
{
	int  iBoardRow, iBoardCol;
	int  iMineRow, iMineCol;
	char cMineCount = '0';

	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		for (iBoardCol = 0; iBoardCol < _iInputCol; ++iBoardCol)
		{
			if ((*pppMineBoard)[iBoardRow][iBoardCol] == '*')
			{
				continue;
			}

			for (iMineRow = iBoardRow - 1; iMineRow <= iBoardRow + 1; ++iMineRow)
			{
				for (iMineCol = iBoardCol - 1; iMineCol <= iBoardCol + 1; ++iMineCol)
				{
					// ������ ��� ���
					if (iMineRow < 0 || iMineRow >= _iInputRow ||
						iMineCol < 0 || iMineCol >= _iInputCol)
					{
						continue;
					}

					// ���� ��ġ�� ����
					if (iMineRow == iBoardRow && iMineCol == iBoardCol)
					{
						continue;
					}

					// ���ڸ� ã�� ���
					if ((*pppMineBoard)[iMineRow][iMineCol] == '*')
					{
						cMineCount++;
					}
				}
			}
			(*pppMineBoard)[iBoardRow][iBoardCol] = cMineCount;
			cMineCount = '0';
		}
	}
}

void PrintResult(char*** pppMineBoard, int _iInputRow, int _iInputCol)
{
	int iBoardRow, iBoardCol;

	puts("���� ������ �Ǵ��� ����� ������ �����ϴ�.");
	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		for (iBoardCol = 0; iBoardCol < _iInputCol; ++iBoardCol)
		{
			printf("%c", (*pppMineBoard)[iBoardRow][iBoardCol]);
		}
		printf("\n");
	}
}