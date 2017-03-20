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

// �ֿ� ���
void InitGameBoard(int GameBoard[][COL]);
void PrintGameBoard(int GameBoard[][COL], int iWho);
int CheckOverlap(int GameBoard[][COL], int iCompare);
int DeleteNumber(int GameBoard[][COL], int iSel);
int WidthCheck(int GameBoard[][COL], int iWidthCnt[ROW]);
int HeightCheck(int GameBoard[][COL], int iHeightCnt[COL]);
int LeftDiagonalCheck(int GameBoard[][COL], int* iLeftDiagonalCnt);
int RightDiagonalCheck(int GameBoard[][COL], int* iRightDiagonalCnt);
int IsBlackBingo(int* iBingoCnt);

// ���� �Լ�
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
	
	// �ʱ�ȭ
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
		printf("���� �÷��̾� ���� �� : %d\n", Player.iBingoCnt);
		printf("���� ��ǻ�� ���� ��   : %d\n", Computer.iBingoCnt);
		puts("========================================");

		// ���� Ȯ��
		if (FinalCheck() == GAME_END)
		{
			break;
		}

		// ���� ����
		PlayerTurn(PlayerBoard, ComputerBoard);
		Sleep(2000);
		ComputerTurn(PlayerBoard, ComputerBoard);

		// ���� ��Ȳ Ȯ��
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
					iCompare = RANDOM(99) + 1; // 1 ~ 99����
					//puts("�� to the ��!");
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
		puts("<<�÷��̾�  ������>>");
	}

	else if (iWho == COMPUTER_BOARD)
	{
		puts("<<��ǻ�� ������>>");
	}

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			if (GameBoard[i][j] == DELTE_DATA) // ���� ����������
			{
				printf("�� "); // �̰� ä���
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
			if (GameBoard[i][j] == iCompare) // ���� ���ٸ�
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
			if (GameBoard[i][j] == iSel) // ���� ���ٸ�
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

	printf("�ƹ� ���ڳ� �Է��ϼ��� : "); scanf("%d", &iSel);
	puts("========================================");
	printf("�÷��̾��� ���� : %d\n", iSel);

	if (DeleteNumber(PlayerBoard, iSel) == MATCHING)
	{
		puts("�÷��̾� ���� ���忡�� ���ڸ� �������ϴ�!");
	}

	else
	{
		puts("�÷��̾� ���� ���忡�� ���� ���ڰ� �����ϴ�!");
	}

	if (DeleteNumber(ComputerBoard, iSel) == MATCHING)
	{
		puts("��ǻ�� ���� ���忡�� ���ڸ� �������ϴ�!");
	}

	else
	{
		puts("��ǻ�� ���� ���忡�� ���� ���ڰ� �����ϴ�!");
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
				if (iSel != DELTE_DATA) // ���� ����ִٸ�
				{
					iCheck = COMPUTER_ACTIVATE;
				}
			}
		}
	}

	puts("========================================");
	printf("��ǻ���� ���� : %d\n", iSel);

	if (DeleteNumber(ComputerBoard, iSel) == MATCHING)
	{
		puts("��ǻ�� ���� ���忡�� ���ڸ� �������ϴ�!");
	}

	else
	{
		puts("��ǻ�� ���� ���忡�� ���� ���ڰ� �����ϴ�!");
	}

	if (DeleteNumber(PlayerBoard, iSel) == MATCHING)
	{
		puts("�÷��̾� ���� ���忡�� ���ڸ� �������ϴ�!");
	}

	else
	{
		puts("�÷��̾� ���� ���忡�� ���� ���ڰ� �����ϴ�!");
	}
}

int PlayerCheck(int PlayerBoard[][COL])
{
	puts("========================================");
	puts("<<�÷��̾� ��Ȳ>>");

	// ���� ����
	if (WidthCheck(PlayerBoard, Player.iWidthCnt) == ROW_BINGO)
	{
		Player.iBingoCnt++;
		puts("���� �����Դϴ�!");
	}

	// ���� ����
	if (HeightCheck(PlayerBoard, Player.iHeightCnt) == COL_BINGO)
	{
		Player.iBingoCnt++;
		puts("���� �����Դϴ�!");
	}

	// ���� �밢�� ����
	if (LeftDiagonalCheck(PlayerBoard, &Player.iLeftDiagonalCnt) == DIAGONAL_BINGO)
	{
		Player.iBingoCnt++;
		puts("���� �밢�� �����Դϴ�!");
	}

	// ������ �밢�� ����
	if (RightDiagonalCheck(PlayerBoard, &Player.iRightDiagonalCnt) == DIAGONAL_BINGO)
	{
		Player.iBingoCnt++;
		puts("������ �밢�� �����Դϴ�!");
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
	puts("<<��ǻ�� ��Ȳ>>");

	// ���� ����
	if (WidthCheck(ComputerBoard, Computer.iWidthCnt) == ROW_BINGO)
	{
		Computer.iBingoCnt++;
		puts("���� �����Դϴ�!");
	}

	// ���� ����
	if (HeightCheck(ComputerBoard, Computer.iHeightCnt) == COL_BINGO)
	{
		Computer.iBingoCnt++;
		puts("���� �����Դϴ�!");
	}

	// ���� �밢�� ����
	if (LeftDiagonalCheck(ComputerBoard, &Computer.iLeftDiagonalCnt) == DIAGONAL_BINGO)
	{
		Computer.iBingoCnt++;
		puts("���� �밢�� �����Դϴ�!");
	}

	// ������ �밢�� ����
	if (RightDiagonalCheck(ComputerBoard, &Computer.iRightDiagonalCnt) == DIAGONAL_BINGO)
	{
		Computer.iBingoCnt++;
		puts("������ �밢�� �����Դϴ�!");
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
		if (iWidthCnt[i] == ROW_BINGO) // ���� ���� ������
		{
			continue; // ���� �� �˻�
		}

		for (j = 0; j < COL; ++j)
		{
			if (GameBoard[i][j] == DELTE_DATA) // ������ ���̶��
			{
				iWidthCnt[i]++; // ���� �� ���� ����

				if (iWidthCnt[i] == ROW_BINGO)
				{
					return ROW_BINGO;
				}
			}
		}

		iWidthCnt[i] = 0; // ���� �ƴϹǷ� ���� �ʱ�ȭ
	}

	return NO_BINGO;
}

int HeightCheck(int GameBoard[][COL], int iHeightCnt[COL])
{
	int i, j;

	for (i = 0; i < COL; ++i)
	{
		if (iHeightCnt[i] == COL_BINGO) // ���� ���� ������
		{
			continue; // ���� �� �˻�
		}

		for (j = 0; j < ROW; ++j)
		{
			if (GameBoard[j][i] == DELTE_DATA) // ������ ���̶��
			{
				iHeightCnt[i]++; // ���� �� ���� ����

				if (iHeightCnt[i] == COL_BINGO)
				{
					return COL_BINGO;
				}
			}
		}

		iHeightCnt[i] = 0; // ���� �ƴϹǷ� ���� �ʱ�ȭ
	}

	return NO_BINGO;
}

int LeftDiagonalCheck(int GameBoard[][COL], int* iLeftDiagonalCnt)
{
	int i, j;

	if (ROW != COL) // ��� ���� �ٸ��� �Ұ���
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	// ���� �밢�� ���� �޼�������
	if (*iLeftDiagonalCnt == DIAGONAL_BINGO)
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			// ��� ���� ���ƾ� ���� ����
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

	if (ROW != COL) // ��� ���� �ٸ��� �Ұ���
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	// ������ �밢�� ���� �޼�������
	if (*iRightDiagonalCnt == DIAGONAL_BINGO)
	{
		return DIAGONAL_IMPOSSIBLE;
	}

	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			// �� + �� == �밢�� ���� ���� - 1
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

	if (ROW == COL) // �밢�� ���� ���� �Ǵ�
	{
		iAllCnt = ROW + COL + 2;
	}

	else
	{
		iAllCnt = ROW + COL;
	}

	// �� ���� �� == ���� ���� ��?
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
			puts("�÷��̾� �������Դϴ�!!! ����!!!");
			puts("���� �ǰ� ���Ͻó׿�~!");
		}

		else if (Player.iWinCheck != BLACK_BINGO && Computer.iWinCheck == BLACK_BINGO)
		{
			puts("��ǻ�� �������Դϴ�!!!");
			puts("�ƾ�... �÷��̾ �����ϴ�...");
		}

		else if (Player.iWinCheck == BLACK_BINGO && Computer.iWinCheck == BLACK_BINGO)
		{
			puts("ȣ��... ���� �����ϴ�.");
		}

		return GAME_END;
	}
}