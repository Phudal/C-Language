#include <stdio.h>

int main()
{
	int i = 0; // �ʱ갪
	int iNum = 10;

	do 
	{
		iNum += 10; // �ݺ��� �ҽ� �ڵ�
		++i;        // ������
	} while (i == 8); // ����
	printf("iNum : %d\n", iNum);
	return 0;
}