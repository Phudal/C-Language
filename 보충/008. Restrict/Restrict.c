#include <stdio.h>
#include <stdlib.h>

int main()
{
	int iNum = 20;
	int* __restrict pOldData = NULL;
	int* __restrict pNewData = NULL;

	pOldData = (int*)malloc(sizeof(int));
	*pOldData = 10;
	pNewData = &iNum;
	*pNewData += *pOldData;
	printf("*pOldData : %d\t*pNewData : %d\n", *pOldData, *pNewData);
	free(pOldData);
	return 0;
}