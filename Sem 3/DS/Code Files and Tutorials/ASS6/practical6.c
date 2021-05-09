#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 10
int front=-1,rear=-1,time=1;
struct library{
	char p;
	int t;	
};
struct library l[MAX];

int isFull();
int isEmpty();
void enqueueFront(int,char);
void enqueueRear(int, char);
void dequeueFront();
void dequeueRear();

int main(){
	int t[5],s[5],i,j=0,flag=0;
	printf("Enter the entry time of teachers: ");
	for(i=0;i<5;i++){
		scanf("%d",&t[i]);
	}
	printf("Enter the entry time of students: ");
	for(i=0;i<5;i++){
		scanf("%d",&s[i]);
	}
	i=0;
	while(i<5&&j<5){
		if(time>t[i]||time==t[i]){
			enqueueFront(time,'T');
			i++;
			time++;
			flag=1;
		}else if(time==s[j]||time>s[j]){
			enqueueRear(time,'S');
			j++;
			time++;
			flag=2;
		}else{
			time++;
			flag=0;
		}
		if(flag==1){
			dequeueFront();
		}else if(flag==2){
			dequeueRear();
		}
	}
	while(i<5){
		enqueueFront(time,'T');
		i++;
		time++;
		dequeueFront();
	}
	while(j<5){
		enqueueRear(time,'S');
		j++;
		time++;
		dequeueRear();
	}
	while(!isEmpty()){
		dequeueFront();
	}
	return 0;
	
}

int isFull(){
	if((front==0&&rear==MAX-1)||(front==rear+1)){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(){
	if(front==-1&&rear==-1){
		return 1;
	}else{
		return 0;
	}
}

void enqueueFront(int ti,char c){
	if(isFull()){
		printf("The queue is full!\n");
		return;
	}else if(isEmpty()){
		front=rear=0;
	}else if(front==0){
		front=MAX-1;
	}else{
		front--;
	}
	l[front].p=c;
	l[front].t=ti;	
}

void enqueueRear(int ti,char c){
	if(isFull()){
		printf("The queue is full!\n");
		return;
	}else if(isEmpty()){
		front=rear=0;
	}else{
		rear=(rear+1)%MAX;
	}
	l[rear].p=c;
	l[rear].t=ti;
}

void dequeueFront(){
	if(isEmpty()){
		return;
	}
	printf("The request served at %d sec: %c\n",l[front].t,l[front].p);
	if(front==rear){
		front=rear=-1;
	}else{
		front=(front+1)%MAX;
	}
}

void dequeueRear(){
	if(isEmpty()){
		return;
	}
	printf("The request served at %d sec: %c\n",l[rear].t,l[rear].p);
	if(front==rear){
		front=rear=-1;
	}else if(rear==0){
		rear=MAX-1;
	}else{
		rear--;
	}
}
