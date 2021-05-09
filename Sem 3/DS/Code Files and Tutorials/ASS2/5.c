#include<stdio.h>
#include "mystring.h"
int main()
{
	char arr='c', str[100];
	int p;
	printf("Enter the string in which position of letter c is to be known: ");
	scanf("%s", &str);
	p=findChar(str,arr);
	if(p==-1){
		printf("Not Found");
	}else{
		printf("Position is:%d\n",p);
	}
	
	return 0;
} 

