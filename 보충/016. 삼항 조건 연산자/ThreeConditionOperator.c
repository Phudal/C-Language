#include <stdio.h>

int main()
{
	int iFlag; // ¦�� Ȧ���� �Ǵ��ϴ� ����
	int iInput;

	printf("���� �ϳ��� �Է��ϼ��� : ");
	scanf("%d", &iInput);

	// ���� ���� �����ڿ����� ���� ������ ��ȣ�� �ʼ�!
	(iInput % 2 == 0) ? 
		((iFlag = 0) ? 
			((iFlag = 1) ? (iFlag = 5) : (iFlag = 6))
			: 
			((iFlag = 2) ? (iFlag = 7) : (iFlag = 8)))
		: 
		((iFlag = 1) ? 
			((iFlag = 3) ? (iFlag = 9) : (iFlag = 10))
			: 
			((iFlag = 4) ? (iFlag = 11) : (iFlag = 12)));
	printf("iFlag�� �� : %d\n", iFlag);
	return 0;
}