#include <stdio.h>
#include <string.h>

#pragma pack(push, 16)
typedef struct tagPlayerInfo
{
	char szName[10];
	unsigned int iLevel;
	unsigned int iHP;
	unsigned int iMP;
}PLAYERINFO;
#pragma pack(pop)

int main()
{
	PLAYERINFO tPlayerInfo;
	
	strcpy(tPlayerInfo.szName, "�濰��");
	tPlayerInfo.iLevel = 1;
	tPlayerInfo.iHP = 360;
	tPlayerInfo.iMP = 40;

	puts("<tPlayerInfo�� �� ��� ũ��>");
	printf("szName : %d����Ʈ\n", sizeof(tPlayerInfo.szName));
	printf("iLevel : %d����Ʈ\n", sizeof(tPlayerInfo.iLevel));
	printf("iHP    : %d����Ʈ\n", sizeof(tPlayerInfo.iHP));
	printf("iMP    : %d����Ʈ\n", sizeof(tPlayerInfo.iMP));
	puts("--------------------------------");
	printf("��� ����� ���� ũ��  : %d����Ʈ\n",
		sizeof(tPlayerInfo.szName) + sizeof(tPlayerInfo.iLevel) +
		sizeof(tPlayerInfo.iHP) + sizeof(tPlayerInfo.iMP));
	printf("�����Ϸ��� �ν��� ũ�� : %d����Ʈ\n", sizeof(PLAYERINFO));
	return 0;
}