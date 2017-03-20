#include <stdio.h>
#include <stdlib.h>

int intCompare(const void* pNum1, const void* pNum2)
{
	return *(int*)pNum2 - *(int*)pNum1;
}

int main(void)
{
	int i, j;
	int iLength;
	int iNum;
	int iDataCount = 0;
	int *pNumList;

	printf("�迭�� ���̸� �Է��ϼ��� : "); scanf("%d", &iLength);
	pNumList = (int *)malloc(sizeof(int) * iLength);
	puts("------------------------------");

	while (1)
	{
		printf("���� �ϳ� �Է� : ");
		scanf("%d", &iNum);

		if (iDataCount < iLength)
		{
			pNumList[iDataCount] = iNum;
			iDataCount++;

			// ���� ��
			printf("\n���� �� ����\n");
			for (i = 0; i < iDataCount; ++i)
			{
				printf("%d ", pNumList[i]);
			}
			puts("");

			qsort(pNumList, iDataCount, 4, intCompare);
		}
		else if (iDataCount == iLength)
		{
			for (i = 0; i < iDataCount; ++i)
			{
				// �Է��� ���� �� ũ�ٸ�
				if (pNumList[i] <= iNum)
				{
					for (j = iDataCount - 2; j >= i; --j)
					{
						pNumList[j + 1] = pNumList[j];
					}
					pNumList[i] = iNum;
					break;
				}
			}
		}

		// ���� ��
		printf("\n���� �� ����\n");
		for (i = 0; i < iDataCount; ++i)
		{
			printf("%d ", pNumList[i]);
		}
		puts("\n------------------------------");
		getchar();
	}
	free(pNumList);
	return 0;
}
