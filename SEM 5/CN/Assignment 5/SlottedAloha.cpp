#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num_of_frames;
    cout<<"Enter number of frames.\n";
    cin>>num_of_frames;
    cout<<"The slots are starting from 0sec and each slot is of 2sec.\n";
    vector< int > v[50];
    int temp;
    for(int i=1; i<=num_of_frames; i++)
    {
        again:
        cout<<"Enter the start time of frame "<<i<<":";
        cin>>temp;
        if(temp%2 != 0)
        {
            cout<<"Its slotted aloha... Pls start form starting of each slots..\n";
            goto again;
        }
        else
        {
            temp /= 2;
            v[temp].push_back(i);
        }
    }
    check:
    bool flag = true;
    for(int i=0; i<50; i++)
    {
        if(v[i].size() > 1) //more than one frames in a slot
        {
            vector< int > te;
            cout<<"There is a collision in the "<<i<<" slot.\n";
            for(int j=0; j<v[i].size(); j++)
            {
                te.push_back(v[i][j]);
            }
            v[i].clear(); //reallocate slots by asking the user start times of collided frames
            for(int j=0; j<te.size(); j++)
            {
                again2:
                cout<<"Enter the start time of frame no. "<<te[j]<<"\n";
                cin>>temp;
                if(temp%2 != 0)
                {
                    cout<<"Its slotted aloha... Pls start form starting of each slots..\n";
                    goto again2;
                }
                else
                {
                    temp /= 2;
                    v[temp].push_back(te[j]);
                }
            }
            flag = false;
        }
    }
    if(!flag)
        goto check;
    else
    {
        for(int i=0; i<50; i++)
        {
            if(v[i].size() == 1)
            {
                cout<<"Frame "<<v[i][0]<<" is in slot "<<i<<" .\n";
            }
        }
    }
}
