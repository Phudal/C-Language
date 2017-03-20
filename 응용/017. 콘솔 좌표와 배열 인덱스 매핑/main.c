#include <stdio.h>
#include <conio.h>
#include "GameUse.h"
#include "myFmod.h"

#pragma comment(lib, "fmod_vc.lib")

#define START_BORDER_POS_X 8
#define START_BORDER_POS_Y 3
#define START_PLAYER_POS_X 12
#define START_PLAYER_POS_Y 5
#define WIDTH	15
#define HEIGHT	15
#define KEY_DOWN 0x8000

char border[HEIGHT][WIDTH];
COORD currentPox;

void fillBorder(void);
void printBorder(void);
int checkCollision(int nextX, int nextY);
void printCharacter(void);
void removeCharacter(void);
void control(void);

int main(void)
{
	system("title 콘솔 좌표 배열 인덱스 매핑");

	memset(border, 0, sizeof(char) * HEIGHT * WIDTH);
	
	SetCur(NO_CURSOR);
	InitFmod();

	SetPos(45, 7);
	puts("콘솔 좌표와");
	SetPos(45, 9);
	puts("배열의 인덱스를");
	SetPos(45, 11);
	puts("매핑시킵니다.");

	SetPos(START_BORDER_POS_X, START_BORDER_POS_Y);
	fillBorder();
	printBorder();

	currentPox.X = START_PLAYER_POS_X;
	currentPox.Y = START_PLAYER_POS_Y;

	printCharacter();

	while (1)
	{
		control();
	}

	system("pause");
	return 0;
}


void fillBorder(void)
{
	for (int i = 0; i < WIDTH; i++)
	{
		border[0][i] = 1;
		border[HEIGHT - 1][i] = 1;
	}

	for (int i = 1; i < HEIGHT - 1; i++)
	{
		border[i][0] = 1;
		border[i][WIDTH - 1] = 1;
	}
}

void printBorder(void)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			SetPos(START_BORDER_POS_X + (x * 2), START_BORDER_POS_Y + y);

			if (border[y][x] == 1)
			{
				printf("■");
			}
		}

		puts("");
	}

	puts("");
}

int checkCollision(int nextX, int nextY)
{
	int nMappingX, nMappingY;

	nMappingX = (nextX - START_BORDER_POS_X) / 2;
	nMappingY = nextY - START_BORDER_POS_Y;

	if (border[nMappingY][nMappingX] == 1)
	{
		PlayCustomSound();

		SetPos(45, 5);
		SetColor(LIGHT_RED);
		puts("충돌이 발생했습니다!");

		Sleep(1000);
		SetPos(45, 5);
		puts("                     ");
		SetColor(LIGHT_GRAY);

		return 0;
	}

	return 1;
}

void printCharacter(void)
{
	SetPos(currentPox.X, currentPox.Y);
	puts("＠");
}

void removeCharacter(void)
{
	SetPos(currentPox.X, currentPox.Y);
	puts(" ");
}

void control(void)
{
	_getch();
	_getch();

	if (GetAsyncKeyState(VK_UP) & KEY_DOWN)
	{
		if (!checkCollision(currentPox.X, currentPox.Y - 1))
		{
			return;
		}

		removeCharacter();
		currentPox.Y--;
		printCharacter();
	}

	else if (GetAsyncKeyState(VK_DOWN) & KEY_DOWN)
	{
		if (!checkCollision(currentPox.X, currentPox.Y + 1))
		{
			return;
		}

		removeCharacter();
		currentPox.Y++;
		printCharacter();
	}

	else if (GetAsyncKeyState(VK_LEFT) & KEY_DOWN)
	{
		if (!checkCollision(currentPox.X - 1, currentPox.Y))
		{
			return;
		}

		removeCharacter();
		currentPox.X--;
		printCharacter();
	}

	else if (GetAsyncKeyState(VK_RIGHT) & KEY_DOWN)
	{
		if (!checkCollision(currentPox.X + 2, currentPox.Y))
		{
			return;
		}

		removeCharacter();
		currentPox.X++;
		printCharacter();
	}
}