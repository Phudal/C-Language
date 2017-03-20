#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 정렬
#pragma pack(push, 1)
typedef struct tagUserInfo
{
	char szName[10];
	int iUserNum;
	int iSignDate;
}USERINFO, *PUSERINFO;
#pragma pack(pop)

void ByteInverter(void** ppData, int iSize)
{
	int i;
	char* aBytes = (char*)malloc(iSize);
	char* pTemp = (char*)(*ppData);

	// 1바이트씩 거꾸로 복사
	for (i = iSize - 1; i >= 0; --i)
	{
		aBytes[i] = *pTemp;
		pTemp++;
	}
	memcpy(*ppData, aBytes, iSize);
	free(aBytes);
}

int main()
{
	USERINFO  tUser;
	PUSERINFO pUser = &tUser;

	strcpy(tUser.szName, "박소민");
	tUser.iUserNum = 1;
	tUser.iSignDate = 20161118;

	puts("---------------------------정보 변환 전--------------------------");
	printf("이름 : %s\t회원 번호 : %-4d\t회원 가입일 : %8d\n",
		tUser.szName, tUser.iUserNum, tUser.iSignDate);
	ByteInverter(&pUser, sizeof(USERINFO));
	puts("");

	puts("---------------------------정보 변환 후--------------------------");
	printf("이름 : %s\t회원 번호 : %-4d\t회원 가입일 : %8d\n",
		tUser.szName, tUser.iUserNum, tUser.iSignDate);
	ByteInverter(&pUser, sizeof(USERINFO));
	puts("");

	puts("---------------------------정보 복원!!!--------------------------");
	printf("이름 : %s\t회원 번호 : %-4d\t회원 가입일 : %8d\n",
		tUser.szName, tUser.iUserNum, tUser.iSignDate);
	puts("");
	return 0;
}
