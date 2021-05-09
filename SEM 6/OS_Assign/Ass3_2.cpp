#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int burst[10],process[10],waiting[10],turnaround[10],priority[10],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    cout<<"Enter Total Number of Process:";
    cin>>n;
 
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP"<<i<<"\n";
        cout<<"Burst Time:";
        cin>>burst[i];
        cout<<"Priority:";
        cin>>priority[i];
        process[i]=i;           
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
 
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
 
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
 
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
 
    waiting[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting[i]=0;
        for(j=0;j<i;j++)
            waiting[i]+=burst[j];
 
        total+=waiting[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turnaround[i]=burst[i]+waiting[i];     //calculate turnaround time
        total+=turnaround[i];
        cout<<"\nP "<<process[i]<<"\t\t  "<<burst[i]<<"\t\t    "<<waiting[i]<<"\t\t\t"<<turnaround[i];
    }
 
    avg_tat=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;
 
    return 0;
}
