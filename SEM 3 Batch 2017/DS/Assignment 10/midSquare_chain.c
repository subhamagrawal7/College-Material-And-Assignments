#include<stdio.h>

int *Divarr[100]={NULL};

struct node
{
    int data;
    struct node *next;
};
//CHAINING WITH DIVISION
int division(int num)
{
    int n,a[6],i,rem;
    n=num*num;
    for(i=0;i<6;i++)
    {
        rem=n%10;
        a[i]=rem;
        n=n/10;
    }
    int key = a[3]*10 + a[2];
    return key;
}

int linearProbDiv(int num)
{
    int key=division(num);
    printf("The data %d has been stored with key %d\n",num,key);
    insert(key,num);
}

void insert(int key,int num)
{
    struct node *temp;
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=num;
    p->next=NULL;
    if(Divarr[key]==NULL)
        Divarr[key]=p;
    else{
        temp=Divarr[key];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=p;
    }
}

void searchDiv(int n)
{
    int key=division(n);
    search(key,n);
}

void search(int key,int n)
{
    struct node *temp;
    if(Divarr[key]==NULL)
        printf("The data is not present in the list\n");
    else{
        temp=Divarr[key];
        while(temp->data!=n && temp!=NULL)
        {
            temp=temp->next;
        }
        if(temp==NULL)
            printf("The data is not present in list.\n");
        else
            printf("The data is present in the list\n");
    }
}

void display()
{
    struct node *temp;
    int i;
    for(i=0;i<100;i++)
    {
        if(Divarr[i]!=NULL)
        {
            printf("At index %d:\t",i);
            temp=Divarr[i];
            while(temp!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
    }
    printf("All Other indexes are empty\n");
}

void main()
{
    int choice,num;
    printf("==============HASHING WITH DIVISION METHOD AND LINEAR PROBING=============\n");
    while(1)
    {
        printf("Choose any one of below:\n1.Insert key\n2.Find Key\n3.DISPLAY\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number\n");
                    scanf("%d",&num);
                    linearProbDiv(num);
                    break;

            case 2: printf("Enter the number to be search\t:");
                    scanf("%d",&num);
                    searchDiv(num);
                    break;

            case 4: exit(0);

            case 3: display();
                    break;
            default: printf("Wrong choice entered\n");
                    break;
        }
    }
}

