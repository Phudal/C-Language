/*
* Name : myFmod.c	ver 1.0
* Content : FMOD 관련 함수 정의
* Implementation : LTG
*
* Last modified 2016 / 03 / 27
*/

/*********************************************************************************************************/
// 전처리기 기능


/*********************************************************************************************************/
// 헤더 파일
#include <stdio.h>
#include "myFmod.h"

/*********************************************************************************************************/
// 매크로 상수 및 함수


/*********************************************************************************************************/
// 구조체 및 공용체


/*********************************************************************************************************/
// 함수 프로토타입


/*********************************************************************************************************/
// 전역 변수
static FMOD_SYSTEM* g_System;
static FMOD_SOUND* g_Sound;
static FMOD_CHANNEL* g_Channel;

/*********************************************************************************************************/
/*
 * 기	능 : FMOD_SYSTEM 반환
 */
FMOD_SYSTEM* GetFmodSystem(void)
{
	return g_System;
}


/*
 * 기	능 : FMOD_SOUND 반환
 */
FMOD_SOUND* GetFmodSound(void)
{
	return g_Sound;
}

/*
 * 기	능 : FMOD_CHANNEL 반환
 */
FMOD_CHANNEL* GetFmodChannel(void)
{
	return g_Channel;
}

/*
 * 기	능 : FMOD 초기 설정
 */
void InitFmod(void)
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	FMOD_System_CreateSound(g_System, "err.wav", FMOD_DEFAULT, NULL, &g_Sound);

	FMOD_Channel_SetVolume(g_Channel, 0.7f);
}

/*
 * 기	능 : FMOD 초기 설정
 */
void PlayCustomSound(void)
{
	FMOD_System_PlaySound(g_System, g_Sound, NULL, 0, &g_Channel);
}