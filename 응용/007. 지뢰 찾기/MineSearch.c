// 기본 헤더 파일
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// 새로 만든 헤더 파일
#include "Constant.h"

int InputBoardInfo(int* _iInputRow, int* _iInputCol)
{
	// 사용자의 입력을 배려 => 가로와 세로 순으로 저장
	printf("게임판의 가로와 세로의 크기를 설정해주세요 : ");
	scanf("%d %d", _iInputCol, _iInputRow);

	if ((*_iInputRow) < 3 || (*_iInputRow) > 10 || (*_iInputCol) < 3 || (*_iInputCol) > 10)
	{
		puts("크기 설정은 3에서 10까지만 가능합니다.");
		return REUTRN_FAIL;
	}
	printf("가로의 크기를 %d, 세로의 크기를 %d로 설정했습니다.\n", *_iInputCol, *_iInputRow);
	puts("------------------------------------------------");
	return RETURN_SUCCESS;
}

int MallocBoard(char*** pppMineBoard, int _iInputRow, int _iInputCol)
{
	int iBoardRow;
	*pppMineBoard = (char**)malloc(sizeof(char*) * _iInputRow);

	if (*pppMineBoard == NULL)
	{
		puts("세로를 동적 할당하지 못했습니다.");
		return REUTRN_FAIL;
	}

	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		(*pppMineBoard)[iBoardRow] = (char*)malloc((sizeof(char) * _iInputCol) + 1);

		if ((*pppMineBoard)[iBoardRow] == NULL)
		{
			puts("가로를 동적 할당하지 못했습니다.");
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

	puts("지뢰 배치를 해주세요.");
	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		scanf("%s", (*pppMineBoard)[iBoardRow]);
	}
	puts("지뢰 배치를 완료했습니다.");
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
					// 범위를 벗어난 경우
					if (iMineRow < 0 || iMineRow >= _iInputRow ||
						iMineCol < 0 || iMineCol >= _iInputCol)
					{
						continue;
					}

					// 현재 위치는 제외
					if (iMineRow == iBoardRow && iMineCol == iBoardCol)
					{
						continue;
					}

					// 지뢰를 찾은 경우
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

	puts("지뢰 개수를 판단한 결과는 다음과 같습니다.");
	for (iBoardRow = 0; iBoardRow < _iInputRow; ++iBoardRow)
	{
		for (iBoardCol = 0; iBoardCol < _iInputCol; ++iBoardCol)
		{
			printf("%c", (*pppMineBoard)[iBoardRow][iBoardCol]);
		}
		printf("\n");
	}
}