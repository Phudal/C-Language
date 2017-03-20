#include <stdio.h>
#include <stdarg.h>

void VariableArgument(char* szArgumentType, ...);

int main()
{
	VariableArgument("LcDi", 206252, 'A', 29.62, 152);
	return 0;
}

void VariableArgument(char* szArgumentType, ...)
{
	va_list ArgumentList;
	va_start(ArgumentList, szArgumentType);

	while(szArgumentType[0] != '\0')
	{
		switch(szArgumentType[0])
		{
		case 'C':
		case 'c':
			printf("char�� ���� ���     : %c\n", va_arg(ArgumentList, char));
			break;
		case 'I':
		case 'i':
			printf("int�� ���� ���      : %d\n", va_arg(ArgumentList, int));
			break; 
		case 'L':
		case 'l':
			printf("long int�� ���� ��� : %ld\n", va_arg(ArgumentList, long int));
			break;
		case 'D':
		case 'd':
			printf("double�� �Ǽ� ���   : %lf\n", va_arg(ArgumentList, double));
			break;
		}
		szArgumentType++; // ���� ���ڷ� �̵�
	}
	va_end(ArgumentList);
}
