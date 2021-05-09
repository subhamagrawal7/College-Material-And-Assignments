#include<stdio.h>
#include "mystring.h"

int stringCompare(char[], char[]);  

int main()
{
    char s1[100], s2[100];
    int compare;

    printf("Enter 1st string: ");
    scanf("%s", s1);

    printf("Enter 2nd string: ");
    scanf("%s", s2);
    compare = strCompare(s1, s2);  
    if(compare == 1)
        printf("Both the strings are exactly same.\n");
     else
        printf("Both the strings are different.\n");

    return 0;
} 
