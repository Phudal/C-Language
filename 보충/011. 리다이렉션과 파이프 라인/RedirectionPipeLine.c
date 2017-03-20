#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("sort Overwatch.txt > OverwatchSort.txt | mkdir New | move OverwatchSort.txt New");
	return 0;
}