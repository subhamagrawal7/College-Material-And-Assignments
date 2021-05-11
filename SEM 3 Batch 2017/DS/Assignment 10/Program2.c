#include <stdio.h>
int MAXSIZE = 8;
int stack[8];
int top = -1;
int isempty() {
 if(top == -1)
 return 1;
 else return 0;}
int isfull() {
 if(top == 7)
 return 1;
 else
 return 0;
}
int peep() {
 return stack[top];
}
int pop() {
 int data;
 if(!isempty()) {
 data = stack[top];
 top =top-1;
 return data;
 }
 else {
 printf("Could not retrieve data, Stack is empty.\n");
 }}
int push(int data) {
 if(!isfull()) {
 top = top + 1;
 stack[top] = data;
 } else {
 printf("Could not insert data, Stack is full.\n");
 }}
int main() {
    int data;
 push(3);
 push(5);
 printf("Element at top of the stack: %d\n" ,peep());
 printf("Elements: \n");
 while(!isempty())
{
    data = pop();
    printf("%d\n",data);
 }
 printf("Stack full: %s\n" , isfull()?"true":"false");
 printf("Stack empty: %s\n" , isempty()?"true":"false");
}
