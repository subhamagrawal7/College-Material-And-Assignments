#include<stdio.h>
#include "mystring.h"
int main()
{
    char string1[100];
    char substring[100];
    int i,flag;
    printf("Enter the string: ");
    scanf("%s", string1);
    printf("Enter the sub string: ");
    scanf("%s", substring);
    flag = substringCheck(string1,substring);  
    
    if(flag == 1)
    {
    printf("Substring is present!\n");	
	}  
     else
     {
     printf("Sub string not present!\n");
	 }      
    return 0;   
}  
