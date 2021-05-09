#include<bits/stdc++.h>

using namespace std;
int cost[5] = {1,1,1,1,1};
int editdist(string str1, string str2, int n, int m) {
        int i, j;
        int dp[n + 1][m + 1];
        for (i = 0; i <= n; i++) {
                for (j = 0; j <= m; j++) {
                        if (i == 0) {
                                dp[i][j] = j * cost[1];
                        } else if (j == 0) {
                                dp[i][j] = i * cost[3];
                        } else if (str1[i - 1] == str2[j - 1]) {
                                dp[i][j] = dp[i - 1][j - 1];
                        } else {
                                int p0 = INT_MAX, p1, p2, p3, p4;
                                if (str1[i - 2] == str2[j - 1] && str1[i - 1] == str2[j - 2] && i >= 2 && j >= 2) {
                                        p0 = dp[i - 2][j - 2] + cost[0]; //twiddle
                                }
                                p1 = cost[1] + dp[i][j - 1]; //insert
                                p2 = cost[2] + dp[i - 1][j - 1]; //replace
                                p3 = cost[3] + dp[i - 1][j]; //delete
                                p4 = cost[4] + dp[i - 1][j - 1]; //copy
                                dp[i][j] = min(p0, min(p1, min(p2, min(p3, p4))));
                        }
                }
        }
        return dp[n][m];
}
int main() {
        string str1, str2;
        cout << "Enter the 1st string : ";
        cin >> str1;
        cout << "Enter the 2nd string : ";
        cin >> str2;
        cout << "Enter the cost of : \n";
        cout << "Twiddle : ";
        cin >> cost[0];
        cout << "Insert : ";
        cin >> cost[1];
        cout << "Replace : ";
        cin >> cost[2];
        cout << "Delete : ";
        cin >> cost[3];
        cout << "Copy : ";
        cin >> cost[4];
        cout << "The minimum cost(bottom up DP): " << editdist(str1, str2, str1.length(), str2.length()) << endl;
        return 0;
}
