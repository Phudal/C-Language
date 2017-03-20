/*
* Name : GameUse.h	ver 1.0
* Content : 게임과 관련된 기본 함수들의 선언
* Implementation : LTG
*
* Last modified 2016 / 03 / 29
*/

/*********************************************************************************************************/
// 전처리기 기능
#pragma once

/*********************************************************************************************************/
// 헤더 파일
#include <Windows.h>
#include <time.h>

/*********************************************************************************************************/
// 매크로 상수 및 함수
#define RANDOMIZE() srand((int)time(NULL))
#define RANDOM(NUM) rand() % NUM

/*********************************************************************************************************/
// 구조체 및 공용체
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
// 함수 프로토타입
void SetPos(int x, int y);
COORD GetPos(void);
void SetColor(ColorName color);
void SetCur(CursorType cursor);


/*********************************************************************************************************/
// 전역 변수


/*********************************************************************************************************/