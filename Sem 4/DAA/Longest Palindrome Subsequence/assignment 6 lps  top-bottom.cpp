#include<bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N][N];
string lps(string str1, string str2, int low, int high) {
        if (low == 0 || high == 0) //empty string & base case
        {
                return string("");
        } else if (str1[low - 1] == str2[high-1]) //end and start position are equal
        {
                return lps(str1, str2, low - 1, high - 1) + str1[low-1]; //find for elements except start and end
        } 
        else if (dp[low - 1][high] > dp[low][high-1])
        {
                return lps(str1, str2, low - 1, high);
        }
        return lps(str1, str2, low, high - 1);
}
int lcs(string str1, string str2, int low, int high) {
        if (low == 0 || high == 0) 
        {
                dp[low][high] = 0;
                return dp[low][high];
        }
        if (dp[low][high] != -1) 
        {
                return dp[low][high];
        }
        if (str1[low - 1] == str2[high-1]) 
        {
                dp[low][high] = lcs(str1, str2, low - 1, high - 1) + 1;
                return dp[low][high];
        } else {
                dp[low][high] = max(lcs(str1, str2, low - 1, high), lcs(str1, str2, low, high-1)); 
                return dp[low][high];
        }
}
int main() {
        string str,revs;
        cout << "Enter the string(top-bottom DP): ";
        cin>>str;
        for (int i = 0; i <= str.length(); i++) {
                for (int j = 0; j <= str.length(); j++) {
                        dp[i][j] = -1;
                }
        }
        revs=str;
        reverse(revs.begin(), revs.end());
        int len=lcs(str, revs, str.length(), str.length());
        cout << "The longest palindromic subsequence(top-down DP)is : "<< lps(str,revs, str.length(), str.length())<<endl<<"The length of the longest palindromic subsequence(top-down DP)is : "<< len;
        return 0;
}
