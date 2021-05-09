#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *root=NULL;

void append();
int length();
void display();
void delete();
void addafter();
void addbefore();
void insert(int);
void reverse();
/**************MAIN**************/
int main(){
	int ch,ch1;
	printf("*******LINKED LIST OPERATIONS********\n");
	printf("1.Create or Append\n2.Insert at a postion\n3.Delete a node\n");
	printf("4.Display all elements\n5.Reverse\n6.Quit\n");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				append();
				break;
			case 2:
				printf("Where do you want to add?\n");
				printf("   1.Before a node\n");
				printf("   2.After a node\n");
				printf("   3.At a particular position\nEnter your request: ");
				scanf("%d",&ch1);
				switch(ch1){
					case 1:
						addbefore();
						break;
					case 2:
						addafter();
						break;
					case 3:
						addbefore();
						break;
					default:
						printf("Enter correct choice.\n");
				}
				break;
			case 3:
				delete();
				break;
			case 4:
				display();
				break;
			case 5:
				reverse();
				break;
			case 6:
				exit(0);
			default:
				printf("Enter correct choice.\n");
				break;
		}
	}
	return 0;
}
/**************MAIN ENDS**************/

/****************************/
void append(){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL){
		root=temp;
	}else{
		struct node *p;
		p=root;
		while(p->link!=NULL){
			p=p->link;
		}
		p->link=temp;
	}
}

/****************************/
int length(){
	int count=0;
	struct node *temp;
	temp=root;
	while(temp!=NULL){
		count++;
		temp=temp->link;
	}
	return count;
}

/****************************/
void display(){
	struct node *temp;
	temp=root;
	if(temp==NULL){
		printf("The list is empty!\n");
	}else{
		printf("The list is: ");
		while(temp!=NULL){
			printf(" %d -->",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

/****************************/
void delete(){
	struct node *temp;
	int loc;
	
	printf("Enter the location to be deleted: ");
	scanf("%d",&loc);
	if(loc>length()){
		printf("Invalid Location!\n");
		return;
	}
	if(loc==1){
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}else{
		struct node *p=root,*q;
		int i=1;
		while(i<loc-1){
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
	printf("The node has been successfully deleted.\n");
}

/****************************/
void addafter(){
	struct node *temp,*p;
	int loc,len,i=1,d;
	printf("Enter the location: ");
	scanf("%d",&loc);
	len=length();
	if(loc>len){
		printf("Invalid location. ");
		printf("Currently list is having %d nodes.\n",len);
	}else{
		insert(loc);
	}
}

/****************************/
void addbefore(){
	int loc,len;
	printf("Enter the location: ");
	scanf("%d",&loc);
	len=length();
	if(len==0){
		printf("The list is empty.\n");
	}else if(loc>len){
		printf("Invalid location. ");
		printf("Currently list is having %d nodes.\n",len);
	}else if(loc==1){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the node data: ");
		scanf("%d",&temp->data);
		temp->link=root;
		root=temp;
		printf("The data has been inserted.\n");
	}else{
		insert(loc-1);
	}
	
}

/****************************/
void insert(int loc){
	struct node *temp,*p;
	int i=1,d;
	p=root;
	while(i<loc){
		p=p->link;
		i++;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted: ");
	scanf("%d",&d);
	temp->link=NULL;
	temp->data=d;
	temp->link=p->link;
	p->link=temp;
	printf("The data has been inserted.\n");
}

void reverse(){
	struct node* p,*q,*temp;
	if(length()==0||length()==1)
		return;
	p=root;
	q=p->link;
	p->link=NULL;
	while(q!=NULL){
		temp=q->link;
		q->link=p;
		p=q;
		q=temp;
	}
	root=p;
	printf("The list has been reversed.\n");
}
