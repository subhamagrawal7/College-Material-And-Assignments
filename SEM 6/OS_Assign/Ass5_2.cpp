#include<bits/stdc++.h>
using namespace std;

int main()
{
int i,j,pages,stream[30],frame[30],frame_no,k,avail,count=0;
cout<<"Enter number of frames: ";
cin>>frame_no;
cout<<"Enter number of pages: ";
cin>>pages;
cout<<"Enter page stream: ";
for(i=1;i<=pages;i++)
cin>>stream[i];            
for(i=0;i<frame_no;i++)
frame[i]=-1;
j=0;
cout<<"Ref string\tPage frames\tRemarks\n";
for(i=1;i<=pages;i++)
{
cout<<"  "<<stream[i]<<"\t\t";
avail=0;
for(k=0;k<frame_no;k++)
{
if(frame[k]==stream[i])
{
avail=1;
break;
}
}
if (avail==0)
{
frame[j]=stream[i];
j=(j+1)%frame_no;
count++;
}
for(k=0;k<frame_no;k++)
cout<<frame[k]<<" ";
if(avail==0)
cout<<"\tPage Fault\n";
else
cout<<"\tPage Found\n";
}

cout<<"Page Fault Is: "<<count;
}

