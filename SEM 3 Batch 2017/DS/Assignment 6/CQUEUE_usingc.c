#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 5

struct plane{
	char name[50];
};
struct runwayQue{
	struct plane p[MAXSIZE];
	int head;
	int tail;
};

struct runwayQue q;
void arrival(char *a){
	q.tail=(q.tail+1)%MAXSIZE;
	if(q.tail==q.head){
		q.tail--;
		printf("The RUNWAY is full\n");
		return;
	}
	else{
		strcpy(q.p[q.tail].name,a);

	}
	if(q.head==-1){
		q.head=0;
	}
}

char *depart(){
	char a[50];
	if(q.head==-1){
		printf("The runway is currently empty\n");
		return '\0';
	}
	if(q.head==q.tail){

		strcpy(a,q.p[q.tail].name);
		q.head=-1;q.tail=-1;
		return q.p[0].name;
	}
	else{
		strcpy(a,q.p[q.head].name);
		q.head=(q.head+1)%MAXSIZE;
		return q.p[q.head-1].name;
	}
}

void main(){
	printf("==============CIRCULAR QUEUE=============\n");
	char s[50];int input;
	q.head=-1;q.tail=-1;
	int j;
	while(1){
            printf("\nChoose any one of the below\n");
            printf("1.Insert plane of the runway\n2.Take off plane from runway\n3.Display planes on the runway\nAnything:-To exit\n");

		scanf("%d",&input);
		switch(input){
			case 1: printf("Name of plane\t:");scanf("%s",s);
                    arrival(s);
                    break;
			case 2: printf("The plane %s has taken off\n",depart());
                    break;
			case 3: if(q.head==-1)printf("\nThe Runway is completely empty\n");
                    else{
                        printf("The planes on the runway are:\t");
                        if(q.head>q.tail)
                            {
                                for(j=q.head;j<MAXSIZE;j++)
                                printf("%s\t",q.p[j].name);
                                for(j=0;j<=q.tail;j++)
                                printf("%s\t",q.p[j].name);
                            }
                        else
                        {
                            for(j=q.head;j<=q.tail;j++)
                            printf("%s \t",q.p[j].name);
                        }
                    }
                    break;
			default:exit(0);
		}
	}
}
