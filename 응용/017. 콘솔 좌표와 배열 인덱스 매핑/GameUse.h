/*
* Name : GameUse.h	ver 1.0
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
#include <Windows.h>
#include <time.h>

/*********************************************************************************************************/
// ��ũ�� ��� �� �Լ�
#define RANDOMIZE() srand((int)time(NULL))
#define RANDOM(NUM) rand() % NUM

/*********************************************************************************************************/
// ����ü �� ����ü
typedef enum _ColorName
{
	BLACK = 0,
	BLUE,
	GREEN,
	SKY,
	RED,
	PINK,
	BROWN,
	LIGHT_GRAY,
	DARK_GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_SKY,
	LIGHT_RED,
	LIGHT_PINK,
	YELLOW,
	WHITE,
	WHITE_BACK
}ColorName;

typedef enum _CursorType
{
	NO_CURSOR,
	SOLID_CURSOR,
	NORMAL_CURSOR
}CursorType;

typedef enum _KeyCheck
{
	EXTEND_KEY	= -32,
	UP			= 72,
	LEFT		= 75,
	RIGHT		= 77
}KeyCheck;

/*********************************************************************************************************/
// �Լ� ������Ÿ��
void SetPos(int x, int y);
COORD GetPos(void);
void SetColor(ColorName color);
void SetCur(CursorType cursor);


/*********************************************************************************************************/
// ���� ����


/*********************************************************************************************************/