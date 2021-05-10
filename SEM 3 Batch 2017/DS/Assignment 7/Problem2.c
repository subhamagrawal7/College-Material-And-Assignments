#include<stdio.h>

struct node
{
    struct node *next;
    int data;
};

struct node *start;

void insertion()
{
    struct node *p,*temp,*t;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\t");
    scanf("%d",&p->data);
    p->next=NULL;

    //check if the list is empty
    if(start==NULL){
        start=p;
    }
    //check if the element is the smallest
    else if(p->data < start->data){
        p->next=start;
        start=p;

    }
    else{
        temp=start;
        //search for the value of the temp bigger than p
        while(temp->next!=NULL && temp->next->data <= p->data)
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
}

void display()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
        printf("The list is currently empty\n");
    else{
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void requiredDeletion()
{
    struct node *temp,*t;
    temp = start;
    if (temp == NULL)
       return;

    while (temp->next != NULL)
    {
       /* Compare current node with next node */
       if (temp->data == temp->next->data)
       {
           t= temp->next->next;
           free(temp->next);
           temp->next = t;
       }
       else {
          temp = temp->next;
       }
    }
}

void main()
{
    int n,i;
    printf("===============DELETE AS FEW NODES SO THAT THE LIST DOESNT CONTAIN ANY REPETED================\n");
    printf("Enter the number of elements in the list:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        insertion();
    printf("The list before deletion is :\n");
    display();
    printf("The list after deletions so that the list doesn't contain repeated elements:\n");
    requiredDeletion();
    display();
}
