// Write a program to copy one string to another string.
#include<stdio.h>
#include "mystring.h"
int main()
{
    char text1[100];
    char text2[100];
    int i;
    printf("Enter the first string: ");
    scanf("%s", text1);
    printf("Enter the second string: ");
    scanf("%s", text2);
    printf("First string copied to Second String successfully as: ");
    printf("%s\n",strCopy(text1,text2));   
}


