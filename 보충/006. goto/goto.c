#include "stdio.h"

int main()
{
	int iNum = 10;

	if (iNum == 100)
	{
Print:
		puts("goto�� �۵�!");
		goto End;
	}
	goto Print;

End:
	return 0;
}