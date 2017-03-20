/*
* Name : GameUse.c	ver 1.0
* Content : 게임과 관련된 기본 함수들의 정의
* Implementation : LTG
*
* Last modified 2016 / 03 / 29
*/

/*********************************************************************************************************/
// 전처리기 기능
#pragma once

/*********************************************************************************************************/
// 헤더 파일
#include "GameUse.h"


/*********************************************************************************************************/
// 매크로 상수 및 함수


/*********************************************************************************************************/
// 구조체 및 공용체


/*********************************************************************************************************/
// 함수 프로토타입


/*********************************************************************************************************/
// 전역 변수


/*********************************************************************************************************/
/*
*	기	능	:	콘솔 좌표 설정하기
*/
void SetPos(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*
*	기	능	:	콘솔 좌표 가져오기
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
*	기	능	:	콘솔 텍스트 색깔 설정하기
*/
void SetColor(ColorName color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*
*	기	능	:	콘솔 커서 설정하기
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
