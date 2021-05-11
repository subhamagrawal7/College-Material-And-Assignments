#include<stdio.h>
#include<string.h>
int front=-1;
int rear=-1;

void insertPlane(char *p,int max_size)
{
    char name[30];
    if ((front == 0 && rear == max_size-1) || (rear == (front-1)%(max_size-1)))
    {
        printf("\nQueue is Full");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        printf("Enter the name of the plane\t:");
        fflush(stdin);
        scanf("%[^\n]s",p[rear]);

        //strcpy(p[rear],name);
    }
    else if (rear == max_size-1 && front != 0)
    {
        rear = 0;
        printf("Enter the name of the plane\t:");
        fflush(stdin);
        scanf("%[^\n]s",p[rear]);
        //strcpy(p[rear],name);
    }
    else
    {
        rear++;
        printf("Enter the name of the plane\t:");
        fflush(stdin);
        scanf("%[^\n]s",p[rear]);
        //strcpy(p[rear],name);
    }
}

void removePlane(char *p,int max_size)
{
    if (front == -1)
    {
        printf("\nRunway is empty");
        return;
    }
    printf("The plane %s has taken off\n",p[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == max_size-1)
        front = 0;
    else
        front++;
}

void showAll(char *p,int max_size)
{
    if (front == -1)
    {
        printf("\nRUNWAY is Empty");
        return;
    }
    printf("\nPlanes on the runway are : ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%s ",p[i]);
    }
    else
    {
        for (int i = front; i < max_size; i++)
            printf("%s ", p[i]);

        for (int i = 0; i <= rear; i++)
            printf("%s ", p[i]);
    }

}

void main()
{
    printf("==========================CIRCULAR QUEUE============================\n");
    printf("Enter the maximum number of planes allowed on the track:\t");
    int max_planes;
    fflush(stdin);
    scanf("%d",&max_planes);
    char plane_name[max_planes][30];
    char *p=&plane_name;
    int choice;
    while(1)
    {
        printf("Choose any one of the below\n");
        printf("1.ALLOW A PLANE ON THE TRACK\n2.PLANE TAKING OFF\n3.CURRENTLY PLANES WHICH ARE ON THE RUNWAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertPlane(p ,max_planes);
                    break;

            case 2: removePlane(p,max_planes);
                    break;

            case 3: showAll(p,max_planes);
                    break;

            case 4: exit(0);

            default: printf("NO SUCH CHOICE AVAILABLE\n");
                     break;

        }
    }
}
