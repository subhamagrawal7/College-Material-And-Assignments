#include<bits/stdc++.h>

using namespace std;
int main()
{
    int arrival[10],burst[10],burst_dup[10];
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

    cout<<"\nEnter the number of Processes: ";  
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter arrival time of process "<<i<<" : ";  
        cin>>arrival[i];
        cout<<"\nEnter burst time of process "<<i<<" : "; 
        cin>>burst[i];
    }
    
    for(i=0; i<n; i++)
        burst_dup[i]=burst[i];

    burst[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(arrival[i]<=time && burst[i]<burst[smallest] && burst[i]>0 )
                smallest=i;
        }
        burst[smallest]--;

        if(burst[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - arrival[smallest] - burst_dup[smallest];
            turnaround[smallest] = end - arrival[smallest];
        }
    }
    cout<<"Process"<<"\t"<< "arrival-time"<<"\t"<<"burst-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i<<"\t\t"<<arrival[i]<<"\t\t"<<burst_dup[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
}
