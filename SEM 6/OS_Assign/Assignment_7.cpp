#include<bits/stdc++.h>
using namespace std;

void SSTF();
void SCAN();

int main()
{
    int Algo=1;
    while(Algo)
    {
        cout<<"Choose Disk Sheduling Algorithm :\n";
        cout<<"1. Shortest Seek Time First (SSTF)\n";
        cout<<"2. SCAN\n";
        cout<<"0. Exit\n";
        cin>>Algo;

        if(!Algo)
            break;

        if(Algo == 1)
            SSTF();
        else if(Algo == 2)
            SCAN();
        else
            cout<<"Invalid Choice!!!\n";
    }
    cout<<"Thank You!";
    return 0;
}

void SSTF()
{
    int headPos,N,tracks;
    bool headDir;
    map <int,int> requests;
    
    cout<<"Enter total number of tracks : ";
    cin>>tracks;
    
    cout<<"Enter current position of R/W head : ";
    cin>>headPos;
    
    cout<<"Enter current dircetion of head movement : \n";
    cout<<"(0 for decreasing track No, 1 for increasing track No )\n";
    cin>>headDir;
    
    cout<<"Enter total no. of requests : ";
    cin>>N;
    
    cout<<"Enter track No.s for all requests by space seprated integers : \n";
    
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        if(temp<0 || temp>=tracks)
        {
            cout<<"\nInvalid Input !!!   This request will be discarded!!\n";
            i--;
        }
        requests[temp]++;
    }
    
    bool flag = 0;
    cout<<"R/W Head will move in follwing sequence : \n";
    while(!requests.empty())
    {
        int leftMove = tracks, rightMove = tracks;
        int leftPos, rightPos;
        map <int,int> :: iterator next = requests.upper_bound(headPos);
        if(next != requests.end())
        {
            rightPos = next->first;
            rightMove = abs (next->first - headPos);
        }
            
        next = requests.lower_bound(headPos);
        if(next != requests.begin())
        {
            next--;
            leftPos = next->first;
            leftMove = abs (next->first - headPos);
        }
        
        
        if(leftMove > rightMove)
        {
            headPos = rightPos;
            headDir = 1;
        }
        else if(leftMove < rightMove)
        {
            headPos = leftPos;
            headDir = 0;
        }
        else
        {
            if(headDir)
                headPos = rightPos;
            else
                headPos = leftPos;
        }
        
        while(requests[headPos]>0)
        {
            if(flag)
                cout<<"->";
            
            flag = 1;
            cout<<headPos;
            requests[headPos]--;
        }
        
        requests.erase(headPos);
    }
    cout<<"\n";
}

void SCAN()
{
    int headPos,N,tracks;
    bool headDir;
    map <int,int> requests;
    
    cout<<"Enter total number of tracks : ";
    cin>>tracks;
    
    cout<<"Enter current position of R/W head : ";
    cin>>headPos;
    
    cout<<"Enter current dircetion of head movement : \n";
    cout<<"(0 for decreasing track No, 1 for increasing track No )\n";
    cin>>headDir;
    
    cout<<"Enter total no. of requests : ";
    cin>>N;
    
    cout<<"Enter track No.s for all requests by space seprated integers : \n";
    
    for(int i=0;i<N;i++)
    {
        int temp;
        cin>>temp;
        if(temp<0 || temp>=tracks)
        {
            cout<<"\nInvalid Input !!!   This request will be discarded!!\n";
            i--;
        }
        requests[temp]++;
    }
    
    bool flag = 0;
    if(requests.find(headPos)!=requests.end())
    {
        while(requests[headPos]--)
        {
            if(flag)
                cout<<"->";
                
            flag = 1;
            cout<<headPos;
        }
        requests.erase(headPos);
    }
    cout<<"R/W Head will move in follwing sequence : \n";
    while(!requests.empty())
    {
        if(headDir)
        {
            map <int,int> :: iterator next = requests.upper_bound(headPos);
            if(next == requests.end())
            {
                headDir = 0;
                headPos = tracks-1;
                
                if(requests.find(headPos)!=requests.end())
                {
                    while(requests[headPos]>0)
                    {
                        if(flag)
                            cout<<"->";
                        
                        flag = 1;
                        cout<<headPos;
                        requests[headPos]--;
                    }
                }
                else
                {
                    if(flag)
                    cout<<"->";
                
                    flag = 1;
                    cout<<headPos;  
                }
                
            }
            else
            {
                headPos = next->first;
                while(requests[headPos]>0)
                {
                    if(flag)
                        cout<<"->";
                    
                    flag = 1;
                    cout<<headPos;
                    requests[headPos]--;
                }
                
                requests.erase(headPos);
            }
        }
        else
        {
            map <int,int> :: iterator next = requests.upper_bound(headPos);
            if(next == requests.begin())
            {
                headPos = 0;
                headDir = 1;
                if(requests.find(headPos)!=requests.end())
                {
                    while(requests[headPos]>0)
                    {
                        if(flag)
                            cout<<"->";
                        
                        flag = 1;
                        cout<<headPos;
                        requests[headPos]--;
                    }
                }
                else
                {
                    if(flag)
                    cout<<"->";
                
                    flag = 1;
                    cout<<headPos;  
                }
            }
            else
            {
                next--;
                headPos = next->first;
                while(requests[headPos]>0)
                {
                    if(flag)
                        cout<<"->";
                    
                    flag = 1;
                    cout<<headPos;
                    requests[headPos]--;
                }
                requests.erase(headPos);
            }  
        }
    }
    cout<<"\n";
}

