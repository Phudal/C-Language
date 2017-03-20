#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef enum FoodType {FT_VEGETABLE, FT_MEAT, FT_SNACK} FOODTYPE;

typedef struct tagFoodInfo
{
	char strName[20];
	int  iShelfLife;
	FOODTYPE eType;
}FOODINFO;

void InitFoodList(FOODINFO** ppFoodList, int iCnt)
{
	*ppFoodList = (FOODINFO*)malloc(sizeof(FOODINFO) * iCnt);
	return;
}

void InputFoodInfo(FOODINFO* _pFoodList)
{
	FOODINFO pFood;

	printf("상품의 이름을 입력하세요 : ");
	gets_s(pFood.strName, sizeof(pFood.strName));

	printf("상품의 유통기한을 입력하세요 : ");
	scanf("%d", &pFood.iShelfLife);

	printf("상품의 종류를 입력하세요 : ");
	scanf("%d", &((int)(pFood.eType)));

	// 검증이 끝난 후 삽입
	*_pFoodList = pFood;
}

void PrintFoodList(FOODINFO* _pFoodList)
{
	printf("상품의 이름     : %s\n", _pFoodList->strName);
	printf("상품의 유통기한 : %d\n", _pFoodList->iShelfLife);
	printf("상품의 종류     : %d\n", (int)(_pFoodList->eType));
}

void SwapSnackInfo(FOODINFO* pSnack1, FOODINFO* pSnack2)
{
	FOODINFO pTemp;
	pTemp     = *pSnack1;
	*pSnack1  = *pSnack2;
	*pSnack2  = pTemp;
}

void DeleteFoodList(FOODINFO** _pFoodList)
{
	free(*_pFoodList);
	*_pFoodList = NULL;
	printf("상품 목록을 삭제했습니다.\n");
}

int main()
{
	int iCnt, i, iFirst, iSecond;
	FOODINFO* pFoodList = NULL;

	while(1)
	{
		int iMenu;
		puts("1. 상품 목록 초기화");
		puts("2. 상품 입력");
		puts("3. 상품 출력");
		puts("4. 상품 교체");
		puts("5. 상품 목록 삭제");
		printf("원하는 메뉴를 입력하세요 : ");
		scanf("%d", &iMenu);
		puts("");
		fflush(stdin);

		switch(iMenu)
		{
		case 1:
			printf("저장할 상품의 개수를 입력하세요 : ");
			scanf("%d", &iCnt);
			InitFoodList(&pFoodList, iCnt);
			printf("\n상품을 %d개 저장했습니다.", iCnt);
			break;
		case 2:
			if (pFoodList == NULL)
			{
				puts("상품 목록이 없습니다.");
				break;
			}

			for (i = 0; i < iCnt; ++i)
			{
				printf("%d 번째 상품의 정보를 입력합니다.\n", i + 1);
				InputFoodInfo(&pFoodList[i]);
				fflush(stdin);

				if (i < iCnt - 1)
				{
					puts("");
				}
			}
			break;
		case 3:
			if (pFoodList == NULL)
			{
				puts("상품 목록이 없습니다.");
				break;
			}

			for (i = 0; i < iCnt; ++i)
			{
				printf("%d 번째 상품 정보\n", i + 1);
				PrintFoodList(&pFoodList[i]);

				if (i < iCnt - 1)
				{
					puts("");
				}
			}
			break;
		case 4:
			printf("바꿀 과자 2개를 입력하세요 : ");
			scanf("%d %d", &iFirst, &iSecond);

			if (iFirst < 1 || iFirst > iCnt ||
				iSecond < 1 || iSecond > iCnt)
			{
				puts("상품 목록 범위를 벗어났습니다.");
				break;
			}

			if (pFoodList[iFirst - 1].eType != FT_SNACK ||
				pFoodList[iSecond - 1].eType != FT_SNACK)
			{
				puts("상품이 과자가 아닙니다.");
				break;
			}

			SwapSnackInfo(&pFoodList[iFirst - 1], &pFoodList[iSecond - 1]);
			printf("%d 번째 상품과 %d 번째 상품의 이름을 바꿨습니다.", iFirst, iSecond);
			break;
		case 5:
			if (pFoodList == NULL)
			{
				printf("상품 목록이 없습니다.");
				break;
			}

			DeleteFoodList(&pFoodList);
			break;
		default:
			printf("잘못된 번호를 입력했습니다.");
			break;
		}
		_getch();
		system("cls");
	}
	return 0;
}