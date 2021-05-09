#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

void append();
struct node* create();
void display();
void search(int data);
void insert(int pos);
void insertBegin();
void insertEnd();
void delete(int pos);
void deleteBegin();
void deleteEnd();
void findMax();
void findMin();

int count=0;

int main(){
	int ch,ch1,data,pos;
	printf("*****DOUBLY LINKED LIST OPERATIONS*****\n");
	printf("  1.Add a node\n  2.Insert at a specific postion\n  3.Delete a node\n");
	printf("  4.Display all elements\n  5.Search an element\n");
	printf("  6.Find Max\n  7.Find Minimum\n  8.Quit\n");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				append();
				break;
			case 2:
				printf("Enter the position where data is to be inserted: ");
				scanf("%d",&pos);
				insert(pos);
				break;
			case 3:
				printf("Enter the position where data is to be deleted: ");
				scanf("%d",&pos);
				delete(pos);
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Enter the data to be searched: ");
				scanf("%d",&data);
				search(data);
				break;
			case 6:
				findMax();
				break;
			case 7:
				findMin();
				break;
			case 8:
				exit(0);
			default:
				printf("Enter correct choice.\n");
				break;
		}
		printf("========================================\n");
	}
	return 0;
}
struct node* create(){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void append(){
	struct node *temp;
	temp=create();
	if(root==NULL){
		root=temp;
	}else{
		struct node *p;
		p=root;
		while(p->right!=NULL){
			p=p->right;
		}
		p->right=temp;
		temp->left=p;	
	}
	count++;
}

void insert(int pos){
	if(pos>count+1){
		printf("ERROR, The list has got only %d nodes!\n",count);
		return;
	}else if(pos==count+1){
		append();
		return;
	}
	if(pos==1){
		insertBegin();
	}else if(pos==count){
		insertEnd();
	}else{
		struct node *temp,*p;
		temp=create();
		p=root;
		int i=1;
		while(i<pos-1){
			p=p->right;
			i++;
		}
		temp->left=p;
		temp->right=p->right;
		p->right->left=temp;
		p->right=temp;
	}
	count++;
}

void insertBegin(){
	struct node *temp;
	temp=create();
	temp->left=NULL;
	temp->right=root;
	root->left=temp;
	root=temp;
}

void insertEnd(){
	struct node *temp,*p=root;
	temp=create();
	while(p->right!=NULL){
		p=p->right;
	}
	temp->left=p;
	p->right=temp;
}

void display(){
	if(root==NULL){
		printf("The list is empty.\n");
		return;
	}
	struct node *temp;
	temp=root;
	printf("The linked list is: ");
	while(temp!=NULL){
		printf("%d --> ",temp->data);
		temp=temp->right;
	}
	free(temp);
	printf("\n");
}

void search(int data){
	if(root==NULL){
		printf("UNDERFLOW.\n");
		return;
	}
	struct node *temp;
	temp=root;
	int countt=0;
	while(temp!=NULL){
		countt++;
		if(data==temp->data){
			break;
		}
		temp=temp->right;
	}
	if(temp==NULL){
		printf("Data not found.\n");
	}else{
		printf("Data found at position %d.\n",countt);
	}
}

void delete(int pos){
	if(root==NULL){
		printf("UNDERFLOW.\n");
		return;
	}
	if(pos>count){
		printf("ERROR, The list has got only %d nodes!\n",count);
		return;
	}else if(pos==1){
		deleteBegin();
	}else if(pos==count){
		deleteEnd();
	}else{
		struct node *temp,*p;
		p=root;
		int i=1;
		while(i<pos-1){
			p=p->right;
			i++;
		}
		temp=p->right;
		temp->right->left=p;
		p->right=temp->right;
		temp->left=NULL;
		temp->right=NULL;
		free(temp);
	}
	count--;
}

void deleteBegin(){
	struct node *temp=root;
	if(root->right==NULL){
		root=NULL;
	}else{
		root->right->left=NULL;
		root=root->right;
	}
	free(temp);
}

void deleteEnd(){
	struct node *temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	temp->left->right=NULL;
	temp->left=NULL;
	free(temp);
}

void findMax(){
	if(root==NULL){
		printf("UNDERFLOW.\n");
		return;
	}
	int temp=root->data;
	struct node *p=root;
	while(p!=NULL){
		if(p->data>temp){
			temp=p->data;
		}
		p=p->right;
	}
	printf("The max element in the linked list is: %d\n",temp);	
}

void findMin(){
	if(root==NULL){
		printf("UNDERFLOW.\n");
		return;
	}
	int temp=root->data;
	struct node *p=root;
	while(p!=NULL){
		if(p->data<temp){
			temp=p->data;
		}
		p=p->right;
	}
	printf("The min element in the linked list is: %d\n",temp);	
}
