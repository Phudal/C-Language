#include <stdio.h>

int main()
{
	int i;
	int iFirstNum, iSecondNum;

	printf("���� 2���� �Է��ϼ��� : ");
	scanf("%d %d", &iFirstNum, &iSecondNum);

	for (i = 1; i <= 100; ++i)
	{
		if (i % (iFirstNum * iSecondNum) == 0)
		{
			printf("FizzBuzz\n");
		} 
		else if (i % iFirstNum == 0)
		{
			printf("Fizz\n");
		}
		else if (i % iSecondNum == 0)
		{
			printf("Buzz\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
	return 0;
}