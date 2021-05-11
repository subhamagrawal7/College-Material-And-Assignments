// Write a program to concate two given string.
#include <stdio.h>
#include "mystring.h"
int main() {
	
  char string1[100],string2[100];
  printf("Enter the first string: ");
	scanf("%s", string1);
	printf("Enter the second string: ");
	scanf("%s", string2);
   printf("%s\n",strConcat(string1,string2));
} 

