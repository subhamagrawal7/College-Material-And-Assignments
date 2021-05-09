#include<bits/stdc++.h>
using namespace std;
#define N 100
int dp[N][N];
string lps(string str1, string str2, int low, int high) {
        if (low == 0 || high == 0) {
                return string("");
        } else if (str1[low - 1] == str2[high - 1]) {
                return lps(str1, str2, low - 1, high - 1) + str1[low - 1];
        } else if (dp[low - 1][high] > dp[low][high - 1]) {
                return lps(str1, str2, low - 1, high);
        }
        return lps(str1, str2, low, high - 1);
}
int lcs(string str1, string str2, int n) {
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                        if (str1[i - 1] == str2[j - 1]) {
                                dp[i][j] = dp[i - 1][j - 1] + 1;
                        } else {
                                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                        }
                }
        }
        return dp[n][n];
}
int main() {
        string str;
        cout << "Enter the string : ";
        cin>>str;
        string revstr = str;
        reverse(revstr.begin(), revstr.end());
        int len=lcs(str, revstr, str.length());
        cout << "The length of the longest palindromic subsequence(bottom-up DP)is : " << lps(str, revstr, str.length(), str.length()) <<endl<<"The longest palindromic subsequence(bottom-up DP)is : "<< len;
        return 0;
}
