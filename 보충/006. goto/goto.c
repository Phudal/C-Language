#include "stdio.h"

int main()
{
	int iNum = 10;

	if (iNum == 100)
	{
Print:
		puts("gotoπÆ ¿€µø!");
		goto End;
	}
	goto Print;

End:
	return 0;
}