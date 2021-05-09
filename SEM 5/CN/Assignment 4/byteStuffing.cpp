#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout<<"Enter in form : F stands for flag, E stands for escape character and D for any other data character\n";
    cout<<"Enter Message to be sent: ";
    cin>>str;
    int i=0,k=0;
    vector<char> t;
    t.push_back('F');
    while(str[i]!='\0')
    {
        if(str[i]=='F'||s[i]=='E')
            t.push_back('E');
        t.push_back(str[i]);
        i++;
    }
    t.push_back('F');
    cout<<"Stuffed message with header and trailer flags is : ";
    for(i=0;i<t.size();i++)
        cout<<t[i];
}