#include <stdio.h>
#include <stdlib.h>

#define IN
#define OUT

typedef enum _InsertFlag
{
	RIGHT, DOWN, LEFT, UP
}INSERTFLAG;

void InputArrayInfo(OUT int *pRow, OUT int *pCol);
int** MallocArray(IN int **ppNumList, int iRow, int iCol);
void InsertArray(OUT int **ppNumList, int iRow, int iCol);
void PrintArray(IN int **ppNumList, int iRow, int iCol);
void FreeArray(OUT int **ppNumList, int iRow);
void ChangeFlag(OUT INSERTFLAG *eInsertFlag);

int main(void)
{
	int iRow, iCol;
	int** ppNumList = NULL;

	while (1)
	{
		// 행과 열 정보 입력
		InputArrayInfo(&iRow, &iCol);

		// 2차원 배열 형식으로 동적 할당
		ppNumList = MallocArray(ppNumList, iRow, iCol);

		// 달팽이 배열 형식으로 대입
		InsertArray(ppNumList, iRow, iCol);

		// 달팽이 형태로 출력
		PrintArray(ppNumList, iRow, iCol);

		// 동적 할당 해제
		FreeArray(ppNumList, iRow);
	}
}

void InputArrayInfo(OUT int *pRow, OUT int *pCol)
{
	printf("행과 열을 입력하세요 : "); scanf("%d %d", pRow, pCol);
	puts("----------------------------------------------");
}

int** MallocArray(IN int **ppNumList, int iRow, int iCol)
{
	int i;
	ppNumList = (int **)malloc(sizeof(int *) * iRow);
	for (i = 0; i < iRow; ++i)
	{
		ppNumList[i] = (int *)malloc(sizeof(int) * iCol);
	}
	return ppNumList;
}

void InsertArray(OUT int **ppNumList, int iRow, int iCol)
{
	int i, j;
	int iRowIdx, iColIdx;
	int iNum;
	int iRowCount, iColCount;
	int iFlagCount;
	int iIdxCount;
	int iDecrease;
	INSERTFLAG eInsertFlag;

	// 변수 초기화
	iRowIdx = 0;
	iColIdx = -1;
	iRowCount = iRow;
	iColCount = iCol;
	iNum = iRow * iCol - 1;
	iFlagCount = 1;
	iIdxCount = 0;
	iDecrease = 0;
	eInsertFlag = RIGHT;

	while (iRowCount != 0 && iColCount != 0)
	{
		if ((iFlagCount % 2) == 0)
		{
			iIdxCount++;
		}

		if (iRowCount != 0)
		{
			for (i = 0; i < iCol - iDecrease; ++i)
			{
				if (eInsertFlag == RIGHT)
				{
					ppNumList[iIdxCount][++iColIdx] = iNum;
				}
				else if (eInsertFlag == LEFT)
				{
					ppNumList[iRow - iIdxCount][--iColIdx] = iNum;
				}
				iNum--;
			}
			iRowCount--;
		}

		// 플래그 전환
		ChangeFlag(&eInsertFlag);

		if (iColCount != 0)
		{
			for (j = 0; j < iRow - iDecrease - 1; ++j)
			{
				if (eInsertFlag == DOWN)
				{
					ppNumList[++iRowIdx][iCol - 1 - iIdxCount] = iNum;
				}
				else if (eInsertFlag == UP)
				{
					ppNumList[--iRowIdx][iIdxCount - 1] = iNum;
				}
				iNum--;
			}
			iColCount--;
		}

		// 플래그 전환
		ChangeFlag(&eInsertFlag);

		iFlagCount++;
		iDecrease++;
	}
}

void PrintArray(IN int **ppNumList, int iRow, int iCol)
{
	int i, j;
	for (i = 0; i < iRow; ++i)
	{
		for (j = 0; j < iCol; ++j)
		{
			printf("%3d ", ppNumList[i][j]);
		}
		puts("");
	}
	puts("----------------------------------------------");
}

void ChangeFlag(OUT INSERTFLAG *eInsertFlag)
{
	switch (*eInsertFlag)
	{
	case RIGHT:
		*eInsertFlag = DOWN;
		break;
	case DOWN:
		*eInsertFlag = LEFT;
		break;
	case LEFT:
		*eInsertFlag = UP;
		break;
	case UP:
		*eInsertFlag = RIGHT;
		break;
	}
}

void FreeArray(OUT int **ppNumList, int iRow)
{
	int i;
	for (i = 0; i < iRow; ++i)
	{
		free(ppNumList[i]);
	}
	free(ppNumList);
}