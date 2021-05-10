#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

bool isFull(int);
int insertPlane(string *,int);
int removePlane(string *,int);
int showAll(string *,int);

int front=-1;
int rear=-1;


int insertPlane(string *p,int max_size)
{
    if ((front == 0 && rear == max_size-1) || (rear == (front-1)%(max_size-1)))
    {
        printf("The RUNWAY is FULLY OCCUPIED\n");
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        printf("Enter the name of the plane\t:");
        cin>>p[rear];
    }
    else if (rear == max_size-1 && front != 0)
    {
        rear = 0;
        printf("Enter the name of the plane\t:");
        cin>>p[rear];
    }
    else
    {
        rear++;
        printf("Enter the name of the plane\t:");
        cin>>p[rear];
    }
}

int removePlane(string *p,int max_size)
{
    if (front == -1)
    {
        printf("The RUNWAY is ALL CLEAR\n");
        return 0;
    }
    cout<<"The Plane===  "<<p[front]<<" ===has taken off"<<endl;
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

int showAll(string *p,int max_size)
{
    if (front == -1)
    {
        cout<<"The Runway Is CLEAR"<<endl;
        return 0;
    }
    cout<<"THE PLANES ON THE RUNWAY"<<endl;
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
           cout<<p[i]<<"\t";
    }
    else
    {
        for (int i = front; i < max_size; i++)
            cout<<p[i]<<"\t";

        for (int i = 0; i <= rear; i++)
            cout<<p[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    cout<<"===================CIRCULAR QUEUE======================\n";

    cout<<"Enter the maximum number of planes allowed on the track:\t";
    int max_planes;
    cin>>max_planes;
    string *p=NULL;
    string name;
    p=new string[max_planes];
    int choice;
    while(1)
    {
        cout<<"======ALL PLANES========"<<endl;
        showAll(p,max_planes);
        cout<<"======ALL PLANES========"<<endl;
        cout<<"Choose any one of the below"<<endl;
        cout<<"1.ALLOW A PLANE ON THE TRACK"<<endl<<"2.PLANE TAKING OFF"<<endl<<"3.CURRENTLY PLANES WHICH ARE ON THE RUNWAY"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: insertPlane(p, max_planes);
                    break;

            case 2: removePlane(p,max_planes);
                    break;

            case 3: showAll(p,max_planes);
                    break;

            default: cout<<"NO SUCH CHOICE AVAILABLE"<<endl;
        }
    }
}
