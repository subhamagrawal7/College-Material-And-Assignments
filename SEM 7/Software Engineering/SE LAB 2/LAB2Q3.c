#include <stdio.h>
int globalVar;

int main() /*@globals undef globalVar @*/
{
	int a;
	a = globalVar;
	return 0;
}
