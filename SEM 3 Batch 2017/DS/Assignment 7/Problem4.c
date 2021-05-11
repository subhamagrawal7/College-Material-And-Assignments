#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;

void insert()
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data\t:");
    scanf("%d",&p->data);
    p->next=NULL;
    if(start==NULL){
        start=p;
        p->next=p;
    }
    else{
        temp=start;
        while(temp->next!=start)
            temp=temp->next;
        temp->next=p;
        p->next=start;
    }
}

void split()
{
    struct node *ptr_1= start;
    struct node *ptr_2= start;
    struct node *start_1,*start_2;

    if(start==NULL)
        return 0;
    else if(start->next==start)
    {
        printf("The first circular linked list is:\n");
        display(start);
        printf("The second circular linked list is empty\n");
        return 0;
    }
    else{
        while(ptr_2->next != start && ptr_2->next->next != start)
          {
             ptr_2 = ptr_2->next->next;
             ptr_1 = ptr_1->next;
          }
        if(ptr_2->next->next == start)
            ptr_2 = ptr_2->next;
        start_1 = start;
        if(start->next != start)
            start_2 = ptr_1->next;
        ptr_2->next = ptr_1->next;
        ptr_1->next = start;

    }
    printf("The first circular linked list is:\n");
    display(start_1);
    printf("The second circular linked list is:\n");
    display(start_2);
}

void display(struct node *start)
{
    struct node *temp;
    temp=start;
    if(start==NULL)
        printf("\nThe list is empty\n");
    else{
        while(temp->next!=start)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\t",temp->data);
        printf("\n");
    }
}

void main()
{
     int i,num_of_nodes;
     printf("===============MAKING A CIRCULAR LINKED LIST INTO TWO================\n");
     printf("Enter the number of nodes you want to insert:\t");
     scanf("%d",&num_of_nodes);
     for(i=0;i<num_of_nodes;i++)
        insert();
     printf("The bigger circular linked list is :\n");
     display(start);
     split();
}
