#include <stdio.h>

int globalVar = 5;

int f(void) /*@globals globalVar;@*/
{
	return 0;
}

int main()
{
	return 0;
}
