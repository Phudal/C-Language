#include <stdio.h>
#include <stdlib.h>

#define STOP system("pause");

typedef struct TagStudent
{
	int iMath;
	int iEnglish;
	int Korean;
}STUDENT;

void main(void)
{
	int iCnt;
	STUDENT* Student;
	int i;
	printf("�� ���� �л��� �Է��� �ǰ���? ");
	scanf("%d", &iCnt);
	Student = (STUDENT*)malloc(sizeof(STUDENT) * 5);

	for (i = 0; i < iCnt; ++i)
	{
		printf("\n%d��° �л��� ������ �Է��մϴ�.\n", i + 1);
		printf("���� ���� : "); scanf("%d", &Student[i].iMath);
		printf("���� ���� : "); scanf("%d", &Student[i].iEnglish);
		printf("���� ���� : "); scanf("%d", &Student[i].Korean);
	}

	printf("\n");

	for (i = 0; i < iCnt; ++i)
	{
		printf("%d��° �л� ��� ���� : %d\n", i + 1, (Student[i].iEnglish + Student[i].iMath + Student[i].Korean) / 3);
	}

	STOP;
}