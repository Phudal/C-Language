#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ü ����
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

	// 1����Ʈ�� �Ųٷ� ����
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

	strcpy(tUser.szName, "�ڼҹ�");
	tUser.iUserNum = 1;
	tUser.iSignDate = 20161118;

	puts("---------------------------���� ��ȯ ��--------------------------");
	printf("�̸� : %s\tȸ�� ��ȣ : %-4d\tȸ�� ������ : %8d\n",
		tUser.szName, tUser.iUserNum, tUser.iSignDate);
	ByteInverter(&pUser, sizeof(USERINFO));
	puts("");

	puts("---------------------------���� ��ȯ ��--------------------------");
	printf("�̸� : %s\tȸ�� ��ȣ : %-4d\tȸ�� ������ : %8d\n",
		tUser.szName, tUser.iUserNum, tUser.iSignDate);
	ByteInverter(&pUser, sizeof(USERINFO));
	puts("");

	puts("---------------------------���� ����!!!--------------------------");
	printf("�̸� : %s\tȸ�� ��ȣ : %-4d\tȸ�� ������ : %8d\n",
		tUser.szName, tUser.iUserNum, tUser.iSignDate);
	puts("");
	return 0;
}
