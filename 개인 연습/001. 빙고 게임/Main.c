#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <memory.h>

#define ROW 5
#define COL 5
#define COL_BINGO ROW
#define ROW_BINGO COL
#define DIAGONAL_BINGO ROW

#define CLEAR system("cls")
#define STOP system("pause")
#define RANDOMIZE() (srand((int)time(NULL)))
#define RANDOM(Num) (rand() % Num)

enum GAME_STATE
{DELTE_DATA = -2, DIAGONAL_IMPOSSIBLE, NO_BINGO, NO_OVERLAP, OVERLAP, NO_MATCHING,
MATCHING, BLACK_BINGO = 7, COMPUTER_ACTIVATE, PLAYER_BOARD, COMPUTER_BOARD, GAME_END};

typedef struct TagGameInfo
{
	int iWinCheck;
	int iBingoCnt;
	int iWidthCnt[ROW];
	int iHeightCnt[COL];
	int iLeftDiagonalCnt;
	int iRightDiagonalCnt;
}GAME_INFO;

// 주요 기능
void InitGameBoard(int GameBoard[][COL]);
void PrintGameBoard(int GameBoard[][COL], int iWho);
int CheckOverlap(int GameBoard[][COL], int iCompare);
int DeleteNumber(int GameBoard[][COL], int iSel);
int WidthCheck(int GameBoard[][COL], int iWidthCnt[ROW]);
int HeightCheck(int GameBoard[][COL], int iHeightCnt[COL]);
int LeftDiagonalCheck(int GameBoard[][COL], int* iLeftDiagonalCnt);
int RightDiagonalCheck(int GameBoard[][COL], int* iRightDiagonalCnt);
int IsBlackBingo(int* iBingoCnt);

// 묶음 함수
void PlayerTurn(int PlayerBoard[][COL], int ComputerBoard[][COL]);
void ComputerTurn(int PlayerBoard[][COL], int ComputerBoard[][COL]);
int PlayerCheck(int PlayerBoard[][COL]);
int ComputerCheck(int ComputerBoard[][COL]);
int FinalCheck(void);

GAME_INFO Player;
GAME_INFO Computer;

void bb(int(*go)[]);

void main(int a, char* b[])
{
	int PlayerBoard[ROW][COL];
	int ComputerBoard[ROW][COL];
	
	// 초기화
	RANDOMIZE();
	system("mode con: lines=40 cols=60");
	memset(&Player, 0, sizeof(GAME_INFO));
	memset(&Computer, 0, sizeof(GAME_INFO));
	InitGameBoard(PlayerBoard);
	InitGameBoard(ComputerBoard);

	while (1)
	{
		PrintGameBoard(PlayerBoard, PLAYER_BOARD);
		puts("");
		PrintGameBoard(ComputerBoard, COMPUTER_BOARD);
		puts("========================================");
		printf("현재 플레이어 빙고 수 : %d\n", Player.iBingoCnt);
		printf("현재 컴퓨터 빙고 수   : %d\n", Computer.iBingoCnt);
		puts("========================================");

		// 최종 확인
		if (FinalCheck() == GAME_END)
		{
			break;
		}

		// 게임 진행
		PlayerTurn(PlayerBoard, ComputerBoard);
		Sleep(2000);
		ComputerTurn(PlayerBoard, ComputerBoard);

		// 현재 상황 확인
		Player.iWinCheck = PlayerCheck(PlayerBoard);
		Computer.iWinCheck = ComputerCheck(ComputerBoard);

		Sleep(2000);
		CLEAR;
	}

	STOP;
}

void InitGameBoard(int GameBoard[][COL])
{
	int i, j;
	int iCompare;
	
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			iCompare = RANDOM(99) + 1;

			while(1)
			{
				if (CheckOverlap(GameBoard, iCompare) == OVERLAP)
				{
					iCompare = RANDOM(99) + 1; // 1 ~ 99까지
					//puts("중 to the 복!");
				}

				else
				{
					break;
				}
			}

			GameBoard[i][j] = iCompare;
		}
	}
}

void PrintGameBoard(int GameBoard[][COL], int iWho)
{
	int i, j;

	if (iWho == PLAYER_BOARD)
	{
		puts("<<플레이어  빙고판>>");
	}

	else if (iWho == COMPUTER_BOARD)
	{
		puts("<<컴퓨터 빙고판>>");
	}

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			if (GameBoard[i][j] == DELTE_DATA) // 값이 지워졌으면
			{
				printf("■ "); // 이거 채우기
			}

			else
			{
				printf("%2d ", GameBoard[i][j]);
			}
		}

		puts("");
	}
}

int CheckOverlap(int GameBoard[][COL], int iCompare)
{
	int i, j;

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			if (GameBoard[i][j] == iCompare) // 값이 같다면
			{
				return OVERLAP;
			}
		}
	}

	return NO_OVERLAP;
}

int DeleteNumber(int GameBoard[][COL], int iSel)
{
	int i, j;

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			if (GameBoard[i][j] == iSel) // 값이 같다면
			{
				GameBoard[i][j] = DELTE_DATA;
				return MATCHING;
			}
		}
	}

	return NO_MATCHING;
}

void PlayerTurn(int PlayerBoard[][COL], int ComputerBoard[][COL])
{
	int iSel;

	printf("아무 숫자나 입력하세요 : "); scanf("%d", &iSel);
	puts("========================================");
	printf("플레이어의 선택 : %d\n", iSel);

	if (DeleteNumber(PlayerBoard, iSel) == MATCHING)
	{
		puts("플레이어 게임 보드에서 숫자를 지웠습니다!");
	}

	else
	{
		puts("플레이어 게임 보드에서 지울 숫자가 없습니다!");
	}

	if (DeleteNumber(ComputerBoard, iSel) == MATCHING)
	{
		puts("컴퓨터 게임 보드에서 숫자를 지웠습니다!");
	}

	else
	{
		puts("컴퓨터 게임 보드에서 지울 숫자가 없습니다!");
	}
}

void ComputerTurn(int PlayerBoard[][COL], int ComputerBoard[][COL])
{
	int i, j = 0;
	int iCheck = 0;
	int iSel = 0;

	while (iCheck != COMPUTER_ACTIVATE)
	{
		iSel = ComputerBoard[RANDOM(ROW)][RANDOM(COL)];

		for (i = 0; i < ROW; ++i)
		{
			for (j = 0; j < COL; ++j)
			{
				if (iSel != DELTE_DATA) // 값이 살아있다면
				{
					iCheck = COMPUTER_ACTIVATE;
				}
			}
		}
	}

	puts("========================================");
	printf("컴퓨터의 선택 : %d\n", iSel);

	if (DeleteNumber(ComputerBoard, iSel) == MATCHING)
	{
		puts("컴퓨터 게임 보드에서 숫자를 지웠습니다!");
	}

	else
	{
		puts("컴퓨터 게임 보드에서 지울 숫자가 없습니다!");
	}

	if (DeleteNumber(PlayerBoard, iSel) == MATCHING)
	{
		puts("플레이어 게임 보드에서 숫자를 지웠습니다!");
	}

	else
	{
		puts("플레이어 게임 보드에서 지울 숫자가 없습니다!");
	}
}

int PlayerCheck(int PlayerBoard[][COL])
{
	puts("========================================");
	puts("<<플레이어 상황>>");

	// 가로 빙고
	if (WidthCheck(PlayerBoard, Player.iWidthCnt) == ROW_BINGO)
	{
		Player.iBingoCnt++;
		puts("가로 빙고입니다!");
	}

	// 세로 빙고
	if (HeightCheck(PlayerBoard, Player.iHeightCnt) == COL_BINGO)
	{
		Player.iBingoCnt++;
		puts("세로 빙고입니다!");
	}

	// 왼쪽 대각선 빙고
	if (LeftDiagonalCheck(PlayerBoard, &Player.iLeftDiagonalCnt) == DIAGONAL_BINGO)
	{
		Player.iBingoCnt++;
		puts("왼쪽 대각선 빙고입니다!");
	}

	// 오른쪽 대각선 빙고
	if (RightDiagonalCheck(PlayerBoard, &Player.iRightDiagonalCnt) == DIAGONAL_BINGO)
	{
		Player.iBingoCnt++;
		puts("오른쪽 대각선 빙고입니다!");
	}

	if (IsBlackBingo(&Player.iBingoCnt) == BLACK_BINGO)
	{
		return BLACK_BINGO;
	}

	return 0;
}

int ComputerCheck(int ComputerBoard[][COL])
{
	puts("========================================");
	puts("<<컴퓨터 상황>>");

	// 가로 빙고
	if (WidthCheck(ComputerBoard, Computer.iWidthCnt) == ROW_BINGO)
	{
		Computer.iBingoCnt++;
		puts("가로 빙고입니다!");
	}

	// 세로 빙고
	if (HeightCheck(ComputerBoard, Computer.iHeightCnt) == COL_BINGO)
	{
		Computer.iBingoCnt++;
		puts("세로 빙고입니다!");
	}

	// 왼쪽 대각선 빙고
	if (LeftDiagonalCheck(ComputerBoard, &Computer.iLeftDiagonalCnt) == DIAGONAL_BINGO)
	{
		Computer.iBingoCnt++;
		puts("왼쪽 대각선 빙고입니다!");
	}

	// 오른쪽 대각선 빙고
	if (RightDiagonalCheck(ComputerBoard, &Computer.iRightDiagonalCnt) == DIAGONAL_BINGO)
	{
		Computer.iBingoCnt++;
		puts("오른쪽 대각선 빙고입니다!");
	}

	if (IsBlackBingo(&Computer.iBingoCnt) == BLACK_BINGO)
	{
		return BLACK_BINGO;
	}

	return 0;
}

int WidthCheck(int GameBoard[][COL], int iWidthCnt[ROW])
{
	int i, j;

	for (i = 0; i < ROW; ++i)
	{
		if (iWidthCnt[i] == ROW_BINGO) // 현재 줄이 빙고라면
		{
			continue; // 다음 줄 검사
		}

		for (j = 0; j < COL; ++j)
		{
			if (GameBoard[i][j] == DELTE_DATA) // 지워진 값이라면
			{
				iWidthCnt[i]++; // 지운 값 개수 증가

				if (iWidthCnt[i] == ROW_BINGO)
				{
					return ROW_BINGO;
				}
			}
		}

		iWidthCnt[i] = 0; // 빙고가 아니므로 개수 초기화
	}

	return NO_BINGO;
}

int HeightCheck(int GameBoard[][COL], int iHeightCnt[COL])
{
	int i, j;

	for (i = 0; i < COL; ++i)
	{
		if (iHeightCnt[i] == COL_BINGO) // 현재 줄이 빙고라면
		{
			continue; // 다음 줄 검사
		}

		for (j = 0; j < ROW; ++j)
		{
			if (GameBoard[j][i] == DELTE_DATA) // 지워진 값이라면
			{
				iHeightCnt[i]++; // 지운 값 개수 증가

				if (iHeightCnt[i] == COL_BINGO)
				{
					return COL_BINGO;
				}
			}
		}

		iHeightCnt[i] = 0; // 빙고가 아니므로 개수 초기화
	}

	return NO_BINGO;
}

int LeftDiagonalCheck(int GameBoard[][COL], int* iLeftDiagonalCnt)
{
	int i, j;

	if (ROW != COL) // 행과 열이 다르면 불가능
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	// 왼쪽 대각선 빙고를 달성했으면
	if (*iLeftDiagonalCnt == DIAGONAL_BINGO)
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			// 행과 열이 같아야 조건 만족
			if (i == j && GameBoard[i][j] == DELTE_DATA)
			{
				(*iLeftDiagonalCnt)++;

				if (*iLeftDiagonalCnt == DIAGONAL_BINGO)
				{
					return DIAGONAL_BINGO;
				}
			}
		}
	}

	*iLeftDiagonalCnt = NO_BINGO;
	return NO_BINGO;
}

int RightDiagonalCheck(int GameBoard[][COL], int* iRightDiagonalCnt)
{
	int i, j;

	if (ROW != COL) // 행과 열이 다르면 불가능
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	// 오른쪽 대각선 빙고를 달성했으면
	if (*iRightDiagonalCnt == DIAGONAL_BINGO)
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			// 행 + 열 == 대각선 빙고 조건 - 1
			if (i + j == DIAGONAL_BINGO - 1 && GameBoard[i][j] == DELTE_DATA)
			{
				(*iRightDiagonalCnt)++;

				if (*iRightDiagonalCnt == DIAGONAL_BINGO)
				{
					return DIAGONAL_BINGO;
				}
			}
		}
	}

	*iRightDiagonalCnt = NO_BINGO;
	return NO_BINGO;
}

int IsBlackBingo(int* iBingoCnt)
{
	int iAllCnt = 0;

	if (ROW == COL) // 대각선 빙고 여부 판단
	{
		iAllCnt = ROW + COL + 2;
	}

	else
	{
		iAllCnt = ROW + COL;
	}

	// 총 빙고 수 == 현재 빙고 수?
	if (iAllCnt == *iBingoCnt)
	{
		return BLACK_BINGO;
	}

	return 0;
}

int FinalCheck(void)
{
	if (Player.iWinCheck == BLACK_BINGO || Computer.iWinCheck == BLACK_BINGO)
	{
		if (Player.iWinCheck == BLACK_BINGO && Computer.iWinCheck != BLACK_BINGO)
		{
			puts("플레이어 블랙빙고입니다!!! 오오!!!");
			puts("빙고를 되게 잘하시네요~!");
		}

		else if (Player.iWinCheck != BLACK_BINGO && Computer.iWinCheck == BLACK_BINGO)
		{
			puts("컴퓨터 블랙빙고입니다!!!");
			puts("아아... 플레이어가 졌습니다...");
		}

		else if (Player.iWinCheck == BLACK_BINGO && Computer.iWinCheck == BLACK_BINGO)
		{
			puts("호오... 서로 비겼습니다.");
		}

		return GAME_END;
	}
}