#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string str) 
{
        for (int i = 0; i < str.length() / 2; i++) {
                if (str[i] != str[str.length() - i - 1]) {
                        return false;
                }
        }
        return true;
}
int main() {
        string str;
        cout << "Enter a string(Iterative):";
        cin >> str;
        int l = 0;
        string subseq;
        for (int i = 0; i < 1 << str.length(); i++) {//2^n possible subsequences
                string sub="";
                for (int j = 0; j < str.length(); j++) //n times
                {
                	//keeps 1 at jth position and performs bitwise and operation 
                   //similar to masking all bits other than the bit at jth position
                        if (i & 1 << j) {
                                sub = sub+str[j];
                        }
                }
                if (ispalindrome(sub) && sub.length() > l) 
                {
                        subseq = sub;
                        l = sub.length();
                }
        }
        cout << "The length of the longest palindromic subsequence(Iterative)is : " << subseq.length() << endl << "The longest palindromic subsequence(Iterative)is : " << subseq;
        return 0;
}
