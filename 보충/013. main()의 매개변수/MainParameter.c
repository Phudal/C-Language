#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	int i;
	printf("입력된 인자의 개수   : %d\n", argc);	
	printf("현재 프로그램의 경로 : %s\n", argv[0]);
	for (i = 1; i < argc; ++i)
	{
		printf("추가된 인자          : %s\n", argv[i]);
	}
	//printf("현재 프로젝트에 필요한 환경 변수 : %s\n", envp[0]);
	return 0;
}