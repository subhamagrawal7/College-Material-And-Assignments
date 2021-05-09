#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CAPACITY 20
int top=-1;
char stackChar[CAPACITY];
void push(char);
int isFull();
int isEmpty();
char pop();

//MAIN------------------------------//
int main(){
	char string[40];
	int i;
	printf("Enter the string: ");
	scanf("%s",string);
	for(i=0;i<strlen(string)/2;i++){
		push(string[i]);
	}
	if(strlen(string)%2!=0){
		i++;
	}
	for(;i<strlen(string);i++){
		if(string[i]!=pop())
		break;
	}
	if(i==strlen(string))
		printf("It is a palindrome.\n");
	else
		printf("It is not a palindrome.\n");
	return 0;
}

//FUNCTIONS
char pop(){
	if(isEmpty()){
		return '\0';
	}else{
		return stackChar[top--];
	}
}
void push(char ch){
	if(isFull()){
		printf("The stack is overflowing.\n");
	}else{
		top++;
		stackChar[top]=ch;
	}
}
int isFull(){
	if(top==CAPACITY-1){
		return 1;
	}else{
		return 0;
	}
}
int isEmpty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}
