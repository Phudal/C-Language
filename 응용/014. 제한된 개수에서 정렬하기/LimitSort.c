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

	printf("배열의 길이를 입력하세요 : "); scanf("%d", &iLength);
	pNumList = (int *)malloc(sizeof(int) * iLength);
	puts("------------------------------");

	while (1)
	{
		printf("숫자 하나 입력 : ");
		scanf("%d", &iNum);

		if (iDataCount < iLength)
		{
			pNumList[iDataCount] = iNum;
			iDataCount++;

			// 정렬 전
			printf("\n정렬 전 정보\n");
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
				// 입력한 값이 더 크다면
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

		// 정렬 후
		printf("\n정렬 후 정보\n");
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
