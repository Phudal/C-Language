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

	// �÷��̾� �ʱ�ȭ
	InitUnit(&Player.Unit, "�÷��̾�", 300, 100, 20, 5, 0, 1000);
	InitPlayer(&Player, "�ٵ�", 1000);

	// ���� �ʱ�ȭ
	InitUnit(&Monster.Unit, "��ö ������", 600, 400, 30, 7, 999, 4000);
	InitMonster(&Monster, 1);

	// ù ���
	PlayerPrint(&Player);
	MonsterPrint(&Monster);

	while(1)
	{
		// �÷��̾� ����
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

		// ���� ����
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
		puts("�÷��̾ �����ߴ�...");
	}

	else if (iWinCheck == PLAYER_WIN)
	{
		puts("�翡������...");
		Sleep(1000);
		PlayerWin(&Player, &Monster);
	}

	Sleep(2500);
	CLEAR;

	// ���� ���
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
	puts("�޾ƶ�!");
	pMonster->Unit.iHp = (pMonster->Unit.iHp + pMonster->Unit.iDefend) - pPlayer->Unit.iDamage;
}

int MonsterAttack(PLAYER* pPlayer, MONSTER* pMonster)
{
	if (pMonster->iDelay != 0)
	{
		puts("���Ͱ� ������ �ִ�!");
		pMonster->iDelay--; // ������ ����
	}

	else
	{
		puts("ũ�ƾ�!");
		pPlayer->Unit.iHp = (pPlayer->Unit.iHp + pPlayer->Unit.iDefend) - pMonster->Unit.iDamage;
		pMonster->iDelay = pMonster->iOriginDelay; // ������ ����
	}
}

void PlayerPrint(PLAYER* pPlayer)
{
	printf("%s(%s)\n", pPlayer->Unit.Name, pPlayer->Job);
	printf("HP : %d / %d | MP : %d / %d | EXP : %d / %d\n", pPlayer->Unit.iHp, pPlayer->Unit.iHpMax, 
		pPlayer->Unit.iMp, pPlayer->Unit.iMpMax, pPlayer->Unit.iExp, pPlayer->iExpMax);
	printf("���ݷ� : %d    | ���� : %d     | ���� �� : %d\n\n", pPlayer->Unit.iDamage, pPlayer->Unit.iDefend,
		pPlayer->Unit.iGold);
}

void MonsterPrint(MONSTER* pMonster)
{
	printf("%s\n", pMonster->Unit.Name);
	printf("HP : %d / %d | MP : %d / %d\n", pMonster->Unit.iHp, pMonster->Unit.iHpMax, 
		pMonster->Unit.iMp, pMonster->Unit.iMpMax);
	printf("���ݷ� : %d    | ���� : %d     | ������ ī��Ʈ : %d\n\n", pMonster->Unit.iDamage,
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
	printf("%s�� �ο��� �̰��!!!\n", pMonster->Unit.Name);
	printf("����ġ %d�� �� %d���� �����!\n", pMonster->Unit.iExp, pMonster->Unit.iGold);
	pPlayer->Unit.iExp += pMonster->Unit.iExp;
	pPlayer->Unit.iGold += pMonster->Unit.iGold;
}