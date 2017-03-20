// �⺻ ��� ����
#include <stdio.h>
#include <stdlib.h>

// ���� ���� ��� ����
#include "MineSearch.h"
#include "Constant.h"

int main()
{
	int iInputRow, iInputCol;
	char** ppMineBoard = NULL;

	system("title ����ã�� ���α׷�");

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
