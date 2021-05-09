#include<bits/stdc++.h>
using namespace std;

int main()
{
    string code_word;
    cout << "Enter the code word: \t" << endl;
    cin >> code_word;
    reverse(code_word.begin(),code_word.end());
    vector<int> code;
    code.push_back(0);
    for (int i = 0; i < code_word.length(); i++)
        code.push_back(code_word[i] - '0');
    int max_pow = floor(log2(code_word.length())) + 1; //maximum power
    vector<int> ans;
    for (int i = 0; i < max_pow; i++)
    {
        int num = pow(2, i); //index from which to start checking
        int cnt = 0;
        for (int j = num; j <= code_word.length(); j += 2 * num)  //skip 2*num bits every time
        {
            for (int k = j; k < j + num && k <= code_word.length(); k++) //for considering consecutive bits 1,2,4... at a time
            {
                if (code[k] == 1)
                    cnt++;
            }
        }
        ans.push_back(cnt%2); //for even parity append "0" and for odd parity append "1"
    }
    int bit = 0;
    int exp = 0;
    for (int & an : ans)
    {
        bit += an * (pow(2, exp)); //convert the binary value to decimal
        exp++;
    }
    if (bit == 0)
    {
        cout << "There is no error in the code word" << endl;
    }
    else
    {
        cout << "There is an error in the " << bit << " bit of the code word." << endl;
    }
}