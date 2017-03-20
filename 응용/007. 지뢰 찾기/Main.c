// 기본 헤더 파일
#include <stdio.h>
#include <stdlib.h>

// 새로 만든 헤더 파일
#include "MineSearch.h"
#include "Constant.h"

int main()
{
	int iInputRow, iInputCol;
	char** ppMineBoard = NULL;

	system("title 지뢰찾기 프로그램");

	if (InputBoardInfo(&iInputRow, &iInputCol) == REUTRN_FAIL)
	{
		return 0;
	}

	if (MallocBoard(&ppMineBoard, iInputRow, iInputCol) == REUTRN_FAIL)
	{
		return 0;
	}

	InputObject(&ppMineBoard, iInputRow);
	SearchMine(&ppMineBoard, iInputRow, iInputCol);
	PrintResult(&ppMineBoard, iInputRow, iInputCol);
	FreeBoard(&ppMineBoard, iInputRow);
	return 0;
}
