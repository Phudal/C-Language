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
			printf("char형 문자 출력     : %c\n", va_arg(ArgumentList, char));
			break;
		case 'I':
		case 'i':
			printf("int형 정수 출력      : %d\n", va_arg(ArgumentList, int));
			break; 
		case 'L':
		case 'l':
			printf("long int형 정수 출력 : %ld\n", va_arg(ArgumentList, long int));
			break;
		case 'D':
		case 'd':
			printf("double형 실수 출력   : %lf\n", va_arg(ArgumentList, double));
			break;
		}
		szArgumentType++; // 다음 문자로 이동
	}
	va_end(ArgumentList);
}
