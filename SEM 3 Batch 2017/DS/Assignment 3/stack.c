#include<stdio.h>
struct book
{
    char name[30];
    int id;
    float price;
};
struct book* createStack(int n,int *top)
{
    struct book *p=NULL;
    p=(struct book *)calloc(n,sizeof(struct book));
    *top= -1;
    return(p);
}
/*int isEmpty(int top)
{
    if(top== -1)
        return(1);
    else
        return(0);
}

int isFull(int top,int max)
{
    if(top=max-1)
        return(1);
    else
        return(0);
}*/
int PUSH(struct book *p,int *top,int max)
 {
     int t,i;
     t=*(top);
     if(t == max-1)
     {
         printf("The stack is overflowing.\n");
     }
     else
     {
         t++;
         printf("Enter the Book Name:\t");
         fflush(stdin);
         scanf("%[^\n]s",(p+t)->name);
         printf("Enter the Book ID:\t");
         scanf("%d",&(p+t)->id);
         printf("Enter the Book Price:\t");
         scanf("%f",&(p+t)->price);
         *top=t;
         return 0;
     }
 }

 void POP(int *top)
 {
     if(*top == -1)
     {
         printf("The stack is underflowing.\n");
     }
    else
    {
        *top = *top - 1;
        printf("POPPING was successful\n");
    }
 }

void PEEP(struct book *p,int *top)
{
    int t;
    t=(*top);
    if(*top == -1)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("The last book added was:\n");
        printf("NAME:\t %s\n",((p+t)->name));
        printf("ID:\t %d\n",((p+t)->id));
        printf("PRICE:\t %f\n",((p+t)->price));

    }

}
void display(struct book *p,int *top)
{
    int t=(*top),i;
    printf("The collection is:\n");
    if(t==-1)
    {
        printf("Empty\n");
    }
    for(i=t;i>=0;i--)
    {
        printf("\nBOOK %d::\n",t-i+1);
        printf("NAME:\t %s\n",((p+t)->name));
        printf("ID:\t %d\n",((p+t)->id));
        printf("PRICE:\t %f\n\n",((p+t)->price));
    }
}
void main()
{
    int max,TOP,n,*m=NULL;
    struct book *p=NULL;
    m=&TOP;
    printf("Enter the maximum number of books:  ");
    scanf("%d",&max);
    p=createStack(n,m);

    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.PEEP\n");
    printf("4.EXIT\n\n\n");

    while(1)
    {
        display(p,m);
        printf("Choose any one of the above\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: PUSH(p,m,max);
                    break;
            case 2: POP(m);
                    break;
            case 3: PEEP(p,m);
                    break;
            case 4: exit(0);
            default: printf("Value entered is not valuable.\n");
                    break;
        }

    }
}
