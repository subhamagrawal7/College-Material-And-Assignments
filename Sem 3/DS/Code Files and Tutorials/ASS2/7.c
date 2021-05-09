#include<stdio.h>
#include "mystring.h"
int main()
{
	char a[20];
	printf("Enter the string to be reversed: ");
	scanf("%s", &a);
	printf("The reversed string is : %s\n",strReverse(a));
} 



