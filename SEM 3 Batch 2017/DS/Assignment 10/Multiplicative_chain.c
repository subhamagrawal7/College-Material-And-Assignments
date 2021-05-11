#include<stdio.h>
int Divarr[100]={0};

//LINEAR PROBING WITH DIVISION
int midSquare(double num)
{
    double random=0.8203;
    double key=(num*random);
    int n = (int)key;
    key = key - n;
    key = (100*key);
    n=(int)key;
    return n;
}

struct node
{
    double data;
    struct node *next;
};

int linearProbMid(double num)
{
    int key=midSquare(num);
    printf("The data %lf has been stored with key %d\n",num,key);
    insert(key,num);
}

void insert(int key,double num)
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

void searchMid(int n)
{
    int key=midSquare(n);
    search(key,n);
}


void search(int key,double n)
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
                printf("%lf\t",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
    }
    printf("All Other indexes are empty\n");
}

void main()
{
    int choice;
    double num;
    printf("==============HASHING WITH MULTIPLICATIVE AND LINEAR PROBING=============\n");
    while(1)
    {
        printf("Choose any one of below:\n1.Insert key\n2.Find Key\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number\n");
                    scanf("%lf",&num);
                    linearProbMid(num);
                    break;

            case 2: printf("Enter the number to be search\t:");
                    scanf("%lf",&num);
                    searchMid(num);
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default: printf("Wrong choice entered\n");
                    break;
        }
    }
}
