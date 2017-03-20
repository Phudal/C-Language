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
	
	strcpy(tPlayerInfo.szName, "흑염룡");
	tPlayerInfo.iLevel = 1;
	tPlayerInfo.iHP = 360;
	tPlayerInfo.iMP = 40;

	puts("<tPlayerInfo의 각 멤버 크기>");
	printf("szName : %d바이트\n", sizeof(tPlayerInfo.szName));
	printf("iLevel : %d바이트\n", sizeof(tPlayerInfo.iLevel));
	printf("iHP    : %d바이트\n", sizeof(tPlayerInfo.iHP));
	printf("iMP    : %d바이트\n", sizeof(tPlayerInfo.iMP));
	puts("--------------------------------");
	printf("모든 멤버의 총합 크기  : %d바이트\n",
		sizeof(tPlayerInfo.szName) + sizeof(tPlayerInfo.iLevel) +
		sizeof(tPlayerInfo.iHP) + sizeof(tPlayerInfo.iMP));
	printf("컴파일러가 인식한 크기 : %d바이트\n", sizeof(PLAYERINFO));
	return 0;
}