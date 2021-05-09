#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i;
    string a;
    cout<<"Enter length of data-word: ";    
    cin>>m;
    //cout<<endl;
    //cout<<"Length of data-word is:- "<<n<<endl;
    cout<<"Enter data-word: ";
    cin>>a;                               
    //cout<<a<<endl;
    char ch[100000];
    n = int(log2(m));  //highest power of 2
    int l = n + m + 1; // length of the word to be transmitted
    int j = 0;
    for(i=1;i<=l;i++)
    {
        if(ceil(log2(i))==floor(log2(i))) //initially set redundancy bits to '0'
        {
            ch[i]='0';
        }
        else
        {
            ch[i]=a[j];
            j+=1;
        }
    }
    int ans=0;
    for(i=1;i<=l;i++)
    {
        ans=0;
        if(ceil(log2(i))==floor(log2(i)))   //for powers of 2 set redundancy bits
        {
            for(j=i;j<=l;j=j+(2*i))         //iterates through all bits correctly
            {
                for(int k=0;k<i;k++)        //no of set of bits to be taken together for checking
                {
                    if(ch[k+j]=='1')
                        ans+=1;
                }
            }
            if(ans&1)       //odd number of 1s -> set redundancy bit to '1'
                ch[i]='1';
        }
    }
    cout<<"Code-Word is:- "<<endl;
    for(i=1;i<=l;i++)
        cout<<ch[i];
}
