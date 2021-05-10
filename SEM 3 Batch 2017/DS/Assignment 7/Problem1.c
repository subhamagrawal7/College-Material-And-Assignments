#include<stdio.h>
 struct node
 {
     struct node *prev;
     int data;
     struct node *next;
 };

 struct node *HEAD=NULL;

 void createNode()
 {
    int num;
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data number:\t");
    scanf("%d",&num);
    p->prev=NULL;
    p->data=num;
    p->next=NULL;

    //CHECK IF HEAD IS EMPTY
    if(HEAD == NULL)
        HEAD=p;
    else
    {
        temp=HEAD;
        while(temp->next != NULL)
            temp=temp->next;
        p->prev=temp;
        temp->next=p;
    }
 }

 void reverse()
 {
    struct node *temp=NULL,*current;
    current=HEAD;
    while(current != NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }

    if(temp!=NULL)
        HEAD = temp->prev;

 }

 void display()
 {
     struct node *temp;
     temp=HEAD;
     //CHECK IF THE LIST IS EMPTY;
     if(temp==NULL)
        printf("The List is empty\n");
     else
     {
         while(temp!=NULL)
         {
             printf("%d ",temp->data);
             temp=temp->next;
         }
         printf("\n");
     }
 }

 void main()
 {
     int i,num_of_nodes;
     printf("================REVERSING A DOUBLY LINKED LIST================\n");
     printf("Enter the number of nodes you want to insert:\t");
     scanf("%d",&num_of_nodes);
     for(i=0;i<num_of_nodes;i++)
        createNode();
     printf("The linked list before reversing is :\n");
     display();
     reverse();
     printf("The linked list after reversing is :\n");
     display();
 }
