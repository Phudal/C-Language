#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
	int i;
	printf("�Էµ� ������ ����   : %d\n", argc);	
	printf("���� ���α׷��� ��� : %s\n", argv[0]);
	for (i = 1; i < argc; ++i)
	{
		printf("�߰��� ����          : %s\n", argv[i]);
	}
	//printf("���� ������Ʈ�� �ʿ��� ȯ�� ���� : %s\n", envp[0]);
	return 0;
}