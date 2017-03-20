#include <stdio.h>
#include <conio.h>

typedef struct tagPlayer
{
	int iScore;
	int iSpeed;
	int iHP;
	int iMP;
}PLAYER;

PLAYER* InitPlayer();

int main()
{
	PLAYER* pPlayer = InitPlayer();
	printf("���� ���� : %8d\t���� �ӵ� : %8d\n", pPlayer->iScore, pPlayer->iSpeed);
	printf("ü��      : %8d\t������    : %8d\n\n", pPlayer->iHP, pPlayer->iMP);

	pPlayer->iHP = 1000; // HP ����
	printf("���� ���� : %8d\t���� �ӵ� : %8d\n", pPlayer->iScore, pPlayer->iSpeed);
	printf("ü��      : %8d\t������    : %8d\n", pPlayer->iHP, pPlayer->iMP);
	_getch();
	return 0;
}

PLAYER* InitPlayer()
{
	static PLAYER tPlayer = {0, 5, 100, 30};
	PLAYER* pPlayer = &tPlayer;
	return pPlayer;
}
