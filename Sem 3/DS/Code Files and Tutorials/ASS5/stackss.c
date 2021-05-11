#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 10
int stack[CAPACITY],TOP=-1,top=-1;
char stackChar[CAPACITY];
void push(int);
void pushChar(char);
int isFull(int);
int isEmpty(int);
int pop();
char popChar();
void peek();
void peekChar();

int main(){
	int choice,item;
	char ch;
	printf("1.Push integer\n2.Pop integer\n3.Peek integer\n4.Push Character\n5.Pop Character\n6.Peek Character\n7.Quit\n");
	
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter element: ");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				item=pop();
				if(item==0){
					printf("The stack is underflowing.\n");
				}else{
					printf("The popped item is: %d\n",item);
				}
				break;
			case 3:
				peek();
				break;
			case 4:
				printf("Enter character: ");
				scanf(" %c",&ch);
				pushChar(ch);
				break;
			case 5:
				ch=popChar();
				if(ch=='\0'){
					printf("The stack is underflowing.\n");
				}else{
					printf("The popped character is: %c\n",ch);
				}
				break;
			case 6:
				peekChar();
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("Enter a valid number!\n");
		}
	}
}
void push(int e){
	if(isFull(TOP)){
		printf("The stack is overflowing.\n");
	}else{
		TOP++;
		stack[TOP]=e;
		printf("Element has been successfully pushed.\n");
	}
}
void pushChar(char ch){
	if(isFull(top)){
		printf("The stack is overflowing.\n");
	}else{
		top++;
		stackChar[top]=ch;
		printf("Character has been successfully pushed.\n");
	}
}
int pop(){
	if(isEmpty(TOP)){
		return 0;
	}else{
		return stack[TOP--];
	}
}
char popChar(){
	if(isEmpty(top)){
		return '\0';
	}else{
		return stackChar[top--];
	}
}
void peek(){
	if(isEmpty(TOP)){
		printf("The stack is empty.\n");
	}else{
		printf("The peeked element is: %d\n",stack[TOP]);
	}
}
void peekChar(){
	if(isEmpty(top)){
		printf("The stack is empty.\n");
	}else{
		printf("The peeked character is: %c\n",stackChar[top]);
	}
}
int isFull(int 	Top){
	if(Top==CAPACITY-1){
		return 1;
	}else{
		return 0;
	}
}
int isEmpty(int Top){
	if(Top==-1){
		return 1;
	}else{
		return 0;
	}
}
