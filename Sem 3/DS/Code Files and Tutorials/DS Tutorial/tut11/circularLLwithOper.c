#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *root=NULL;
int count=0; //Keeps count of number of elements
void append();
void display(struct node *start);
void delete(int);
void deleteBeginning();
void deleteEnd();
void insertAt(int);
void swap();
void deleteAlt();
void split();
struct node* create();

/**************MAIN**************/
int main(){
	int ch,ch1,loc;
	printf("*******LINKED LIST OPERATIONS********\n");
	printf("1.Add a node\n2.Insert a node at a particular postion\n3.Delete a node\n");
	printf("4.Display all elements\n5.Swap\n6.Delete Alternate\n7.Split\n8.Quit\n");
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
				display(root);
				break;
			case 5:
				swap();
				break;
			case 6:
				deleteAlt();
				break;
			case 7:
				split();
				break;
			case 8:
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

void display(struct node *start){
	struct node *temp;
	temp=start;
	if(temp==NULL){
		printf("The list is empty!\n");
	}else{
		printf("The list is: ");
		while(temp->link!=start){
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
	printf("The node has been successfully deleted.\n");
	count--;
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
/****************************/
void swap(){
	if(root==NULL){
		printf("List is Empty!\n");
		return;
	}
	struct node *temp,*p,*q=NULL;
	if(count==2){
		temp=root;
		p=temp->link;
		root=p;
		p->link=temp;
		temp->link=p;
	}
	else if(count>2){
		p=root;
		temp=root;
		while(p->link!=root){
			q=p;
			p=p->link;
		}
		root=p;
		p->link=temp->link;
		q->link=temp;
		temp->link=root;
	}
	printf("Elements have been swapped.\n");
}
/****************************/
void deleteAlt(){
	if(root==NULL){
		printf("List is Empty!\n");
		return;
	}
	struct node *temp;
	temp=root;
	while(temp->link!=root){
		temp->link=temp->link->link;
		temp=temp->link;
		if(temp==root){
			break;
		}
	}
	printf("The alternate items have been deleted.\n");
}
/****************************/
void split(){
	if(count==0||count==1){
		printf("The list cannot be split.\n");
		return;
	}
	struct node *slowptr,*fastptr,*root2;
	slowptr=root;
	fastptr=root;
	while(fastptr->link!=root&&fastptr->link->link!=root){
		slowptr=slowptr->link;
		fastptr=fastptr->link->link;
	}
	
	if(fastptr->link==root){
		fastptr->link=slowptr->link;
		root2=slowptr->link;
		slowptr->link=root;
	}else if(fastptr->link->link==root){
		fastptr->link->link=slowptr->link;
		root2=slowptr->link;
		slowptr->link=root;
	}
	printf("The lists have been split from the middle.\n");
	printf("(First) ");
	display(root);
	printf("(Second) ");
	display(root2);
}

