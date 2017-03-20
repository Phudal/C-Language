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

	printf("��ǰ�� �̸��� �Է��ϼ��� : ");
	gets_s(pFood.strName, sizeof(pFood.strName));

	printf("��ǰ�� ��������� �Է��ϼ��� : ");
	scanf("%d", &pFood.iShelfLife);

	printf("��ǰ�� ������ �Է��ϼ��� : ");
	scanf("%d", &((int)(pFood.eType)));

	// ������ ���� �� ����
	*_pFoodList = pFood;
}

void PrintFoodList(FOODINFO* _pFoodList)
{
	printf("��ǰ�� �̸�     : %s\n", _pFoodList->strName);
	printf("��ǰ�� ������� : %d\n", _pFoodList->iShelfLife);
	printf("��ǰ�� ����     : %d\n", (int)(_pFoodList->eType));
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
	printf("��ǰ ����� �����߽��ϴ�.\n");
}

int main()
{
	int iCnt, i, iFirst, iSecond;
	FOODINFO* pFoodList = NULL;

	while(1)
	{
		int iMenu;
		puts("1. ��ǰ ��� �ʱ�ȭ");
		puts("2. ��ǰ �Է�");
		puts("3. ��ǰ ���");
		puts("4. ��ǰ ��ü");
		puts("5. ��ǰ ��� ����");
		printf("���ϴ� �޴��� �Է��ϼ��� : ");
		scanf("%d", &iMenu);
		puts("");
		fflush(stdin);

		switch(iMenu)
		{
		case 1:
			printf("������ ��ǰ�� ������ �Է��ϼ��� : ");
			scanf("%d", &iCnt);
			InitFoodList(&pFoodList, iCnt);
			printf("\n��ǰ�� %d�� �����߽��ϴ�.", iCnt);
			break;
		case 2:
			if (pFoodList == NULL)
			{
				puts("��ǰ ����� �����ϴ�.");
				break;
			}

			for (i = 0; i < iCnt; ++i)
			{
				printf("%d ��° ��ǰ�� ������ �Է��մϴ�.\n", i + 1);
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
				puts("��ǰ ����� �����ϴ�.");
				break;
			}

			for (i = 0; i < iCnt; ++i)
			{
				printf("%d ��° ��ǰ ����\n", i + 1);
				PrintFoodList(&pFoodList[i]);

				if (i < iCnt - 1)
				{
					puts("");
				}
			}
			break;
		case 4:
			printf("�ٲ� ���� 2���� �Է��ϼ��� : ");
			scanf("%d %d", &iFirst, &iSecond);

			if (iFirst < 1 || iFirst > iCnt ||
				iSecond < 1 || iSecond > iCnt)
			{
				puts("��ǰ ��� ������ ������ϴ�.");
				break;
			}

			if (pFoodList[iFirst - 1].eType != FT_SNACK ||
				pFoodList[iSecond - 1].eType != FT_SNACK)
			{
				puts("��ǰ�� ���ڰ� �ƴմϴ�.");
				break;
			}

			SwapSnackInfo(&pFoodList[iFirst - 1], &pFoodList[iSecond - 1]);
			printf("%d ��° ��ǰ�� %d ��° ��ǰ�� �̸��� �ٲ���ϴ�.", iFirst, iSecond);
			break;
		case 5:
			if (pFoodList == NULL)
			{
				printf("��ǰ ����� �����ϴ�.");
				break;
			}

			DeleteFoodList(&pFoodList);
			break;
		default:
			printf("�߸��� ��ȣ�� �Է��߽��ϴ�.");
			break;
		}
		_getch();
		system("cls");
	}
	return 0;
}