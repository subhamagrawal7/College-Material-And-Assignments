#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;

void insert(int);
struct node* deletion(struct node* p, int data);
struct node* findMin(struct node* p);
int findHeight(struct node* start);
int max(int a,int b);
int main(){
	int ch,data;
	printf("*****BINARY TREE OPERATIONS*****\n");
	printf("1.Insert\n2.Delete\n3.Find Height\n4.Updation\n");
	printf("5.Quit\n");
	while(1){
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter data: ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
				printf("Enter data to be deleted: ");
				scanf("%d",&data);
				deletion(root,data);
				break;
			case 3:
				printf("The height is: %d\n",findHeight(root));
				break;
			case 4:
				printf("Enter the value to be updated: ");
				scanf("%d",&data);
				deletion(root,data);
				printf("Enter the new value: ");
				scanf("%d",&data);
				insert(data);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Enter correct choice!\n");
		}
	}
	return 0;
}
void insert(int d){
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	p=root;
	if(root==NULL){
		root=temp;
	}else{
		struct node* curr;
		curr=root;
		while(curr!=NULL){
			p=curr;
			if(temp->data>curr->data){
				curr=curr->right;
			}else{
				curr=curr->left;
			}
		}
		if((temp->data)>p->data){
			p->right=temp;
		}else{
			p->left=temp;
		}
	}
}

struct node* deletion(struct node* p, int data){
	if(p==NULL){
		return p;
	}else if(data<p->data){
		p->left=deletion(p->left,data);
	}else if(data>p->data){
		p->right=deletion(p->right,data);
	}else{
		if(p->left==NULL && p->right==NULL){
			///NO CHILD
			free(p);
			p=NULL;
		}else if(p->left==NULL){
			struct node* temp=p;
			p=p->right;
			free(temp);
		}else if(p->right==NULL){
			struct node* temp=p;
			p=p->left;
			free(temp);
		}else{
			/// 2 CHILDren
			struct node *temp=findMin(p->right);
			p->data=temp->data;
			p->right=deletion(p->right,temp->data);
		}
		return p;
	}
}

struct node* findMin(struct node* p){
	while(p->left!=NULL){
		p=p->left;
	}
	return p;
}

int findHeight(struct node* start){
	if(start==NULL){
		return -1;
	}
	return max(findHeight(start->left),findHeight(start->right))+1;
}

int max(int a,int b){
	if(a<=b){
		return b;
	}
	return a;
}
