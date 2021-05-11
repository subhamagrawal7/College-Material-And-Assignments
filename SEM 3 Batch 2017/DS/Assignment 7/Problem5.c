#include<stdio.h>
int stack[15];
int top1=-1;
int popStack[15];
int top2=-1;

int push(int page)
{
    if(top1>=14)
    {
        printf("No further going forward is allowed\n");
        return 0;
    }
    top1++;
    stack[top1]=page;

}

int push2(int page)
{
    if(top2>=14)
    {
        return 0;
    }
    popStack[++top2]=page;

}

int pop()
{
    int num;
    if(top1==-1)
    {
        printf("No going back is allowed\n");
        return 0;
    }
    num=stack[top1--];
    return num;
}

int pop2()
{
    int num;
    if(top2==-1)
    {
        return 0;
    }
    num=popStack[top2--];
    return num;
}

void present()
{
    if(top1==-1)
        printf("Currently at no page\n");
    else
        printf("Currently at page no %d\n",stack[top1]);
}

void main()
{++top1
    int choice,page,p;
    while(1)
    {
        present();
        printf("Choose any one of the below\n");
        printf("1.Next page\n2.Previous page\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:  p=pop2();
                     if(p==0){
                        printf("Enter page number:\t");
                        scanf("%d",&page);
                        push(page);
                     }
                     else{
                        push(p);
                     }
                     break;

            case 2:  page=pop();
                     if(page!=0)
                     {
                         push2(page);
                     }
                     break;

            case 3:  exit(0);

            default: printf("Wrong key chosen\n");
                     break;
        }

    }
}
