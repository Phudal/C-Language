#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 5      // �ִ� ����
int* g_pData[MAX_DATA]; // ���� ������

int* Add(int iNum1, int iNum2)
{
	int* pResult = (int*)malloc(sizeof(int)); // ���� ������ �Ҵ�
	*pResult = iNum1 + iNum2;
	//free(pResult);
	return pResult;
}

int main()
{
	int i;
	g_pData[0] = Add(10, 20);
	g_pData[1] = Add(30, 40);
	g_pData[2] = Add(50, 60);
	g_pData[3] = Add(70, 80);
	g_pData[4] = Add(90, 100);

	for (i = 0; i < MAX_DATA; ++i)
	{
		printf("g_pData[%d]�� �� : %d\n", i, *g_pData[i]);
	}
	putchar('\n');

	for (i = 0; i < MAX_DATA; ++i)
	{
		free(g_pData[i]); // �Ҵ�� ���� ����
	}
	return 0;
}