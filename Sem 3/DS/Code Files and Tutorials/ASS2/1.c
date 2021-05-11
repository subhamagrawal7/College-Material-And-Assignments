//Write a program to find the length of a given string.
#include<stdio.h>
#include "mystring.h"
int main(){
	char str[100];
	printf("Enter the string: ");
	scanf("%s", &str);
	printf("Length of string is %d",strLength(str));	
}

