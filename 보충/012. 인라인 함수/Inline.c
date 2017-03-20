#include <stdio.h>
#include <stdlib.h>

int __declspec(noinline) Add(int iNum1, int iNum2)
{
	return iNum1 + iNum2;
}

int main()
{
	printf("°á°ú : %d\n", Add(10, 20));
	return 0;
}