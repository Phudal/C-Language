/*
* Name : GameUse.c	ver 1.0
* Content : ���Ӱ� ���õ� �⺻ �Լ����� ����
* Implementation : LTG
*
* Last modified 2016 / 03 / 29
*/

/*********************************************************************************************************/
// ��ó���� ���
#pragma once

/*********************************************************************************************************/
// ��� ����
#include "GameUse.h"


/*********************************************************************************************************/
// ��ũ�� ��� �� �Լ�


/*********************************************************************************************************/
// ����ü �� ����ü


/*********************************************************************************************************/
// �Լ� ������Ÿ��


/*********************************************************************************************************/
// ���� ����


/*********************************************************************************************************/
/*
*	��	��	:	�ܼ� ��ǥ �����ϱ�
*/
void SetPos(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*
*	��	��	:	�ܼ� ��ǥ ��������
*/
COORD GetPos(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	COORD pos;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	pos.X = curInfo.dwCursorPosition.X;
	pos.Y = curInfo.dwCursorPosition.Y;

	return pos;
}

/*
*	��	��	:	�ܼ� �ؽ�Ʈ ���� �����ϱ�
*/
void SetColor(ColorName color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*
*	��	��	:	�ܼ� Ŀ�� �����ϱ�
*/
void SetCur(CursorType cursor)
{
	CONSOLE_CURSOR_INFO curInfo;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	switch (cursor)
	{
		case NO_CURSOR:
			curInfo.bVisible = FALSE;
			break;

		case SOLID_CURSOR:
			curInfo.dwSize = 100;
			curInfo.bVisible = TRUE;
			break;

		case NORMAL_CURSOR:
			curInfo.dwSize = 20;
			curInfo.bVisible = TRUE;
			break;
	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
