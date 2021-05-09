#include<bits/stdc++.h>
using namespace std;

void addStr(string s1,string &s2,char &carry)
{
    carry='0';
    int l1=s1.length();
    for(int i=l1-1;i>=0;i--)
    {
        if(s1[i]=='0' && s2[i]=='0' && carry=='0')
        {
            s2[i]='0';
            carry='0';
        }
        else if(s1[i]=='0' && s2[i]=='0' && carry=='1')
        {
            s2[i]='1';
            carry='0';
        }
        else if(s1[i]=='0' && s2[i]=='1' && carry=='0')
        {
            s2[i]='1';
            carry='0';
        }
        else if(s1[i]=='0' && s2[i]=='1' && carry=='1')
        {
            s2[i]='0';
            carry='1';
        }
        else if(s1[i]=='1' && s2[i]=='0' && carry=='0')
        {
            s2[i]='1';
            carry='0';
        }
        else if(s1[i]=='1' && s2[i]=='0' && carry=='1')
        {
            s2[i]='0';
            carry='1';
        }
        else if(s1[i]=='1' && s2[i]=='1' && carry=='0')
        {
            s2[i]='0';
            carry='1';
        }
        else if(s1[i]=='1' && s2[i]=='1' && carry=='1')
        {
            s2[i]='1';
            carry='1';
        }
    }
}
void complementString(string &str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='0')
            str[i]='1';
        else
            str[i]='0';
    }
}
int main()
{
    string s[5];
    cout<<"Enter the IPv4 packet:"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>s[i];
    }
    vector<string>v;
    for(int i=0;i<5;i++)
    {
        string str="";
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]>='A')
            {
                int val = s[i][j] - 'A' + 10;
                string s = bitset<4>(val).to_string();
                str += s;
            }
            else
            {
                int val = s[i][j] - '0';
                string s = bitset<4>(val).to_string();
                str+=s;
            }
        }
        v.push_back(str);
    }

    /*for(int i=0;i<5;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<endl;*/
    char carry='0';
    //string sum = bitset<16>(0).to_string();
    string sum2 = bitset<16>(0).to_string();
    for(int i=0;i<5;i++)
    {
        addStr(v[i],sum2,carry);
        if(carry=='1')
        {
            string sum = bitset<16>(1).to_string();
            //sum[sum.length()-1]='1';
            addStr(sum, sum2, carry);
            //carry='0';
        }
    }
    if(carry=='1')
    {
        string sum = bitset<16>(0).to_string();
        sum[sum.length()-1]='1';
        addStr(sum,sum2,carry);
    }
    /*for(int i=0;i<sum2.length();i++)
        cout<<sum2[i];
    cout<<endl;*/
    complementString(sum2);
    for(int i=0;i<sum2.length();i++)
        cout<<sum2[i];
    return 0;
}