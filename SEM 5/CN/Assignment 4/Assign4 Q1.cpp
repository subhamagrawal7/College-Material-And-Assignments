#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"The flag used here is 01111110 and header and trailer is ignored.\n";
    again:
    cout<<"Enter the data to be sent\n";
    string s;
    cin>>s;
    int flag = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '0' || s[i] == '1')
        {
            continue;
        }
        else
        {
            cout<<"Please enter a binary data.\n";
            flag = 1;
            break;
        }
    }
    if(flag)
        goto again;

    string f = "01111110";
    string code_word;
    bool fl = false;
    for(int i=0; i<8; i++)
        code_word.push_back(f[i]);
    for(int i=0; i<6; i++)
        code_word.push_back(s[i]);
    for(int i=6; i<s.length(); i++)
    {
        int cnt = 0;
        //cout<<i<<endl;
        for(int j=i-6; j<i; j++)
        {
            if(s[j] == f[j-(i-6)])
            {
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        if(cnt == 6)
        {
            code_word.push_back('0');
        }
        code_word.push_back(s[i]);
    }
    for(int i=0; i<8; i++)
        code_word.push_back(f[i]);
    cout<<"The codeword generated including flags is:\n"<<code_word<<endl;
}
