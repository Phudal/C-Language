#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define STOP system("pause")
#define CLEAR system("cls")

typedef struct TagUnit
{
	char Name[20];
	int iHp;
	int iHpMax;
	int iMp;
	int iMpMax;
	int iDamage;
	int iDefend;
	int iExp;
	int iGold;
}UNIT;

typedef struct TagPlayer
{
	char Job[20];
	int iExpMax;
	UNIT Unit;
}PLAYER;

typedef struct TagMonster
{
	int iDelay;
	int iOriginDelay;
	UNIT Unit;
}MONSTER;

enum {PLAYER_WIN = 1, MONSTER_WIN};

int InitUnit(UNIT* pUnit, char Name[20], int iHp, int iMp,
	int iDamage, int iDefend, int iExp, int iGold);
int InitPlayer(PLAYER* pPlayer, char Job[20], int iExpMax);
int InitMonster(MONSTER* pMonster, int iDelay);
int PlayerAttack(PLAYER* pPlayer, MONSTER* pMonster);
int MonsterAttack(PLAYER* pPlayer, MONSTER* pMonster);
void PlayerPrint(PLAYER* pPlayer);
void MonsterPrint(MONSTER* pMonster);
int IsHpZero(UNIT* pUnit);
void PlayerWin(PLAYER* pPlayer, MONSTER* pMonster);

void main(void)
{
	PLAYER Player;
	MONSTER Monster;
	int iWinCheck;

	// 플레이어 초기화
	InitUnit(&Player.Unit, "플레이어", 300, 100, 20, 5, 0, 1000);
	InitPlayer(&Player, "바드", 1000);

	// 몬스터 초기화
	InitUnit(&Monster.Unit, "강철 달팽이", 600, 400, 30, 7, 999, 4000);
	InitMonster(&Monster, 1);

	// 첫 출력
	PlayerPrint(&Player);
	MonsterPrint(&Monster);

	while(1)
	{
		// 플레이어 공격
		PlayerAttack(&Player, &Monster);
		if (IsHpZero(&Monster.Unit))
		{
			iWinCheck = PLAYER_WIN;
			break;
		}
		Sleep(800);
		CLEAR;
		PlayerPrint(&Player);
		MonsterPrint(&Monster);

		// 몬스터 공격
		MonsterAttack(&Player, &Monster);
		if (IsHpZero(&Player.Unit))
		{
			iWinCheck = MONSTER_WIN;
			break;
		}
		Sleep(800);
		CLEAR;
		PlayerPrint(&Player);
		MonsterPrint(&Monster);
	}

	Sleep(1000);
	CLEAR;

	PlayerPrint(&Player);
	MonsterPrint(&Monster);

	if (iWinCheck == MONSTER_WIN)
	{
		puts("플레이어가 기절했다...");
	}

	else if (iWinCheck == PLAYER_WIN)
	{
		puts("꿰에에에엑...");
		Sleep(1000);
		PlayerWin(&Player, &Monster);
	}

	Sleep(2500);
	CLEAR;

	// 최종 출력
	PlayerPrint(&Player);
	MonsterPrint(&Monster);

	STOP;
}

int InitUnit(UNIT* pUnit, char Name[20], int iHp, int iMp,
	int iDamage, int iDefend, int iExp, int iGold)
{
	strcpy(pUnit->Name, Name);
	pUnit->iHp = iHp;
	pUnit->iHpMax = iHp;
	pUnit->iMp = iMp;
	pUnit->iMpMax = iMp;
	pUnit->iDamage = iDamage;
	pUnit->iDefend = iDefend;
	pUnit->iExp = iExp;
	pUnit->iGold = iGold;
}

int InitPlayer(PLAYER* pPlayer, char Job[20], int iExpMax)
{
	strcpy(pPlayer->Job, Job);
	pPlayer->iExpMax = iExpMax;
}

int InitMonster(MONSTER* pMonster, int iDelay)
{
	pMonster->iDelay = iDelay;
	pMonster->iOriginDelay = iDelay;
}

int PlayerAttack(PLAYER* pPlayer, MONSTER* pMonster)
{
	puts("받아랏!");
	pMonster->Unit.iHp = (pMonster->Unit.iHp + pMonster->Unit.iDefend) - pPlayer->Unit.iDamage;
}

int MonsterAttack(PLAYER* pPlayer, MONSTER* pMonster)
{
	if (pMonster->iDelay != 0)
	{
		puts("몬스터가 가만히 있다!");
		pMonster->iDelay--; // 딜레이 감소
	}

	else
	{
		puts("크아아!");
		pPlayer->Unit.iHp = (pPlayer->Unit.iHp + pPlayer->Unit.iDefend) - pMonster->Unit.iDamage;
		pMonster->iDelay = pMonster->iOriginDelay; // 딜레이 복원
	}
}

void PlayerPrint(PLAYER* pPlayer)
{
	printf("%s(%s)\n", pPlayer->Unit.Name, pPlayer->Job);
	printf("HP : %d / %d | MP : %d / %d | EXP : %d / %d\n", pPlayer->Unit.iHp, pPlayer->Unit.iHpMax, 
		pPlayer->Unit.iMp, pPlayer->Unit.iMpMax, pPlayer->Unit.iExp, pPlayer->iExpMax);
	printf("공격력 : %d    | 방어력 : %d     | 가진 돈 : %d\n\n", pPlayer->Unit.iDamage, pPlayer->Unit.iDefend,
		pPlayer->Unit.iGold);
}

void MonsterPrint(MONSTER* pMonster)
{
	printf("%s\n", pMonster->Unit.Name);
	printf("HP : %d / %d | MP : %d / %d\n", pMonster->Unit.iHp, pMonster->Unit.iHpMax, 
		pMonster->Unit.iMp, pMonster->Unit.iMpMax);
	printf("공격력 : %d    | 방어력 : %d     | 딜레이 카운트 : %d\n\n", pMonster->Unit.iDamage,
		pMonster->Unit.iDefend, pMonster->iDelay);
}

int IsHpZero(UNIT* pUnit)
{
	if (pUnit->iHp <= 0)
	{
		pUnit->iHp = 0;
		return 1;
	}

	return 0;
}

void PlayerWin(PLAYER* pPlayer, MONSTER* pMonster)
{
	printf("%s랑 싸워서 이겼다!!!\n", pMonster->Unit.Name);
	printf("경험치 %d와 돈 %d원을 얻었다!\n", pMonster->Unit.iExp, pMonster->Unit.iGold);
	pPlayer->Unit.iExp += pMonster->Unit.iExp;
	pPlayer->Unit.iGold += pMonster->Unit.iGold;
}