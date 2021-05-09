#include<stdio.h>
#include<string.h>
#define CAPACITY 20
int top1=-1,top2=-1;
char stack1[CAPACITY],stack2[CAPACITY];
void push(char,char stack[]);
int isFull(char stack[]);
int isEmpty(char stack[]);
char pop(char stack[]);

/********** MAIN BEGINS ************/
int main(){
	char string[20];
	int i;
	printf("Enter a string: ");
	scanf("%s",string);
	push(string[0],stack1);
	i=1;
	while(i<strlen(string)){
		while(!isEmpty(stack1)){
			if((int)stack1[top1]<(int)string[i]){
				push(pop(stack1),stack2);
			}else{
				break;
			}
		}
		push(string[i],stack1);
		while(!isEmpty(stack2)){
			push(pop(stack2),stack1);
		}
		i++;
	}
	printf("The sorted string is: ");
	while(!isEmpty(stack1)){
		printf("%c",pop(stack1));
	}
	return 0;
}
/********** MAIN ENDS ************/


char pop(char stack[]){
	if(isEmpty(stack)){
		return '\0';
	}else{
		if(stack==stack1){
			return stack1[top1--];
		}else{
			return stack2[top2--];
		}
	}
}
void push(char ch,char stack[]){
	if(isFull(stack)){
		printf("The stack is overflowing.\n");
	}else{
		if(stack==stack1){
			top1++;
			stack1[top1]=ch;
		}else{
			top2++;
			stack2[top2]=ch;
		}
	}
}
int isFull(char stack[]){
	if(stack==stack1){
		if(top1==CAPACITY-1){
			return 1;
		}else
		{
			return 0;
		}
	}else{
		if(top2==CAPACITY-1){
			return 1;
		}else
		{
			return 0;
		}
	}
}
int isEmpty(char stack[]){
	if(stack==stack1){
		if(top1==-1){
			return 1;
		}else
		{
			return 0;
		}
	}else{
		if(top2==-1){
			return 1;
		}else
		{
			return 0;
		}
	}
	
}
