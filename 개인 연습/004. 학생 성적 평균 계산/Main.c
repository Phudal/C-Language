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
	printf("몇 명의 학생을 입력할 건가요? ");
	scanf("%d", &iCnt);
	Student = (STUDENT*)malloc(sizeof(STUDENT) * 5);

	for (i = 0; i < iCnt; ++i)
	{
		printf("\n%d번째 학생의 성적을 입력합니다.\n", i + 1);
		printf("수학 성적 : "); scanf("%d", &Student[i].iMath);
		printf("영어 성적 : "); scanf("%d", &Student[i].iEnglish);
		printf("국어 성적 : "); scanf("%d", &Student[i].Korean);
	}

	printf("\n");

	for (i = 0; i < iCnt; ++i)
	{
		printf("%d번째 학생 평균 성적 : %d\n", i + 1, (Student[i].iEnglish + Student[i].iMath + Student[i].Korean) / 3);
	}

	STOP;
}