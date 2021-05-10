#include<stdio.h>

struct node
{
    struct node *next;
    int data;
};

struct node *start;

void createNode()
 {
    int num;
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data number:\t");
    scanf("%d",&num);
    p->data=num;
    p->next=NULL;

    //CHECK IF HEAD IS EMPTY
    if(start == NULL)
        start=p;
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=p;
    }
 }

 void display()
 {
     struct node *temp;
     temp=start;
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

void swap(int n)
{
    int i;
    struct node *temp,*t=NULL,*swap;
    if(n==1)
    {
       temp=start;
       start=start->next;
       temp->next=start->next;
       start->next=temp;
    }
    else{
        temp=start;
        for(i=0;i<n-1;i++)
        {
            t=temp;
            temp=temp->next;
        }
        swap=temp->next;
        temp->next=temp->next->next;
        swap->next=temp;
        t->next=swap;
    }
}

void main()
{
    int n,i;
    printf("=============SWAPPING TWO CONSECUTIVE NODES==============\n");
    printf("Enter the number of nodes to be inserted in the list:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        createNode();
    printf("Currently the list is:\n ");
        display();
    printf("Enter the node number to be swapped with its right node:\t");
    scanf("%d",&i);
    if(i>n || i<1)
        printf("The node doesn't exist\n");
    else if(i==n)
        printf("There exits no node to the right to swap the node\n");
    else
        swap(i);
    printf("The list after swapping is:\n ");
        display();
}
