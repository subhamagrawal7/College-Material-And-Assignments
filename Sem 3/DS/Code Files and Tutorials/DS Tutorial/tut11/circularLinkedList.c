
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *root=NULL;
int count=0;
void append();
void display();
void delete(int);
void deleteBeginning();
void deleteEnd();
void insertAt(int);
struct node* create();

/**************MAIN**************/
int main(){
	int ch,ch1,loc;
	printf("*******LINKED LIST OPERATIONS********\n");
	printf("1.Add a node\n2.Insert a node at a particular postion\n3.Delete a node\n");
	printf("4.Display all elements\n5.Quit\n");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				append();
				break;
			case 2:
				printf("Enter the location to be inserted: ");
				scanf("%d",&loc);
				insertAt(loc);
				break;
			case 3:
				printf("Enter the location to be deleted: ");
				scanf("%d",&loc);
				delete(loc);
				break;
			case 4:
				display();
				break;
			case 5:
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
struct node* create(){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data: ");
	scanf("%d",&temp->data);
	temp->link=root;
	return temp;
}
/****************************/
void append(){
	struct node *temp;
	temp=create();
	if(root==NULL){
		root=temp;
		temp->link=root;
	}else{
		struct node *p;
		p=root;
		while(p->link!=root){
			p=p->link;
		}
		p->link=temp;
	}
	count++;
}

/****************************/
void display(){
	struct node *temp;
	temp=root;
	if(temp==NULL){
		printf("The list is empty!\n");
	}else{
		printf("The list is: ");
		while(temp->link!=root){
			printf(" %d -->",temp->data);
			temp=temp->link;
		}
		printf(" %d -->",temp->data);
		printf("\n");
	}
}

/****************************/
void deleteBeginning(){
	struct node *temp,*p;
	temp=root;
	if(root->link==root){
		root=NULL;
	}else{
		p=root;
		while(p->link!=root){
			p=p->link;
		}
		p->link=root->link;
		root=root->link;
		free(temp);
	}
}
/****************************/
void delete(int loc){
	struct node *temp;
	if(loc>count){
		printf("Invalid Location!\n");
		return;
	}
	if(loc==1){
		deleteBeginning();	
	}else if(loc==count){
		deleteEnd();
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
	count--;
	printf("The node has been successfully deleted.\n");
}
/****************************/
void deleteEnd(){
	struct node *temp;
	temp=root;
	if(count==1){
		root=NULL;
	}else{
		while(temp->link->link!=root){
			temp=temp->link;
		}
		temp->link=root;	
	}
}
/****************************/
void insertAt(int loc){
	struct node *temp,*p;
	if(loc>count){
		printf("Invalid Location!\n");
		return;
	}
	int i=1;
	temp=create();
	p=root;
	if(loc==1&&count==1){
		root=temp;
		temp->link=p;
		p->link=root;
	}else if(loc==1){
		while(p->link!=root){
			p=p->link;
		}
		temp->link=root;
		root=temp;
		p->link=temp;
	}else if(loc==count){
		while(p->link->link!=root){
			p=p->link;
		}
		temp->link=p->link;
		p->link=temp;
		
	}else{
		while(i<loc-1){
		p=p->link;
		i++;
		}
		temp->link=p->link;
		p->link=temp;
	}
	
	printf("The data has been inserted.\n");
	count++;
}
