/*
* Name : myFmod.c	ver 1.0
* Content : FMOD ���� �Լ� ����
* Implementation : LTG
*
* Last modified 2016 / 03 / 27
*/

/*********************************************************************************************************/
// ��ó���� ���


/*********************************************************************************************************/
// ��� ����
#include <stdio.h>
#include "myFmod.h"

/*********************************************************************************************************/
// ��ũ�� ��� �� �Լ�


/*********************************************************************************************************/
// ����ü �� ����ü


/*********************************************************************************************************/
// �Լ� ������Ÿ��


/*********************************************************************************************************/
// ���� ����
static FMOD_SYSTEM* g_System;
static FMOD_SOUND* g_Sound;
static FMOD_CHANNEL* g_Channel;

/*********************************************************************************************************/
/*
 * ��	�� : FMOD_SYSTEM ��ȯ
 */
FMOD_SYSTEM* GetFmodSystem(void)
{
	return g_System;
}


/*
 * ��	�� : FMOD_SOUND ��ȯ
 */
FMOD_SOUND* GetFmodSound(void)
{
	return g_Sound;
}

/*
 * ��	�� : FMOD_CHANNEL ��ȯ
 */
FMOD_CHANNEL* GetFmodChannel(void)
{
	return g_Channel;
}

/*
 * ��	�� : FMOD �ʱ� ����
 */
void InitFmod(void)
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);

	FMOD_System_CreateSound(g_System, "err.wav", FMOD_DEFAULT, NULL, &g_Sound);

	FMOD_Channel_SetVolume(g_Channel, 0.7f);
}

/*
 * ��	�� : FMOD �ʱ� ����
 */
void PlayCustomSound(void)
{
	FMOD_System_PlaySound(g_System, g_Sound, NULL, 0, &g_Channel);
}