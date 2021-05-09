#include<bits/stdc++.h>
using namespace std;

string xordivide(string s1,string s2)
{
    string xorid;
    int i;
    int l=s1.length();
    for(i=0;i<l;i++)
    {
        if(s1[i]=='1' && s2[i]=='1')
        xorid.push_back('0');
        else if(s1[i]=='1' && s2[i]=='0')
        xorid.push_back('1');
        else if(s1[i]=='0' && s2[i]=='1')
        xorid.push_back('1');
        else if(s1[i]=='0' && s2[i]=='0')
        xorid.push_back('0');
    }
    //cout<<xorid<<endl;
    return xorid;
}

string divide(string a, string b,int n,int m,string ans)
{
    int i,j = m-1;
    string xori,t,temp;
    for(i=0;i<m;i++)
    xori.push_back('0');
    for(i=0;i<m;i++)
    t.push_back(a[i]);
    while(j<a.size())
    {
        temp = t;
        //cout<<t<<endl;
        if(temp[0]=='0')
        {
            t = xordivide(temp,xori);
        }
        else
        {
            t = xordivide(temp,b);
        }
        j+=1;
        if(j<a.size())
        {
            t.erase(t.begin());
            t.push_back(a[j]);
            //cout<<t<<"hi"<<endl;
        }
        else
        break;
    }
    cout<<"Remainder:- "<<endl;
    for(i=1;i<t.length();i++)
    {
        cout<<t[i];
    }
    cout<<endl;
    for(i=1;i<t.length();i++)
    {
        ans.push_back(t[i]);
    }
    return ans;
}

int main()
{
    string a,b,ans;
    int i,j,k,n,m;
    cout<<"Enter dividend"<<endl;
    cin>>a;     //100010
    //cout<<a<<endl;
    ans = a;
    cout<<"Enter divisor"<<endl;
    cin>>b;     //1000
    //cout<<b<<endl;
    n = a.length(); //Dividend
    m = b.length(); //Divisor
    for(i=1;i<=(m-1);i++)
    {
        a.push_back('0');
    }
    string fin = divide(a,b,n,m,ans);
    cout<<"Corrected codeword is :- "<<fin<<endl;
}
