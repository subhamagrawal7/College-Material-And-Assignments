#include <stdio.h>

int globalVar;

int main() /*@globals undef globalVar @*/
{
	return globalVar;
}
