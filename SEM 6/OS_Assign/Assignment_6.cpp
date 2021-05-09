#include <bits/stdc++.h>
using namespace std;

int main()
{
    int processes,resources,completedNo=0;
    cout<<"Enter total no of processes : ";     cin>>processes;
    cout<<"Enter total no of types of resources : ";     cin>>resources;
    
    int allocatedResouces[processes][resources]={};
    int requestedResources[processes][resources]={};
    int available[resources];
    int seq[processes];
    bool completed[processes]={};
    start:
    //take input for total resorces
    cout<<"Enter total available resorces : \n";
    for(int j=0;j<resources;j++)
    {
        cout<<"R"<<j+1<<" : ";
        cin>>available[j];
    }
    
    //take input total requested resouces
    cout<<"Enter total resources requested by processes  : \n";
    for(int i=0;i<processes;i++)
    {
        cout<<"P"<<i+1<<" : ";
        for(int j=0;j<resources;j++)
        {
            if(j)cout<<"     ";
            cout<<"R"<<j+1<<" : ";
            cin>>requestedResources[i][j];
            if(available[j]< requestedResources[i][j])
            {
                cout<<"Process "<<i+1<<" cannot be completed in anyway!!! Start Again:(";
                goto start;
            }
        }
    }
    
    cout<<"Enter resources allocated to processes in current state : \n";
    for(int i=0;i<processes;i++)
    {
        cout<<"P"<<i+1<<" : ";
        for(int j=0;j<resources;j++)
        {
            if(j)cout<<"     ";
            cout<<"R"<<j+1<<" : ";
            cin>>allocatedResouces[i][j];
            available[j] -= allocatedResouces[i][j];
            if(available[j]<0)
            {
                cout<<"Allocation cannot be done !!! Start Again :(";
                goto start;
            }
        }
    }
    
    for(int k=0;k<processes;k++)
    {
        int i;
        for(i=0;i<processes;i++)
        {
            if(!completed[i])
            {
                int j;
                for(j=0;j<resources;j++)
                {
                    if(available[j] <  requestedResources[i][j] - allocatedResouces[i][j])
                        break;
                }
                
                if(j==resources)
                {
                    completed[i] = 1;
                    for(j=0;j<resources;j++)
                        available[j] += allocatedResouces[i][j];
                    seq[k]=i;
                    completedNo++;
                    break;
                }
            }
        }
        if(i == processes)
        {
            //Unsafe state
            cout<<"This state will lead to Deadlock.";
            if(!completedNo)
            {
                cout<<"Current State is Deadlock";
            }
            else
            {
                cout<<"Possible sequence to complete maximum processes before deadlock :\n";
                for(int i=0;i<processes && i<completedNo;i++)
                {
                    if(i) cout<<"->";
                    cout<<"P"<<seq[i]+1;
                }
            }
            return 0;
        }
    }
    cout<<"This is safe state. One of the possible sequence to complete all processes is \n";
    for(int i=0;i<processes;i++)
    {
        if(i) cout<<"->";
        cout<<"P"<<seq[i]+1;
    }
    return 0;
}



