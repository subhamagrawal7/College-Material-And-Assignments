#include<bits/stdc++.h>
using namespace std;
int cost[5] = {1,1,1,1,1};
int editdist(string str1, string str2, int n, int m) {
        if (n == 0) {
                return m;//length of string
        }
        if (m == 0) {
                return n;//length of string
        }
        if (str1[n - 1] == str2[m - 1]) {
                return editdist(str1, str2, n - 1, m - 1);//remove last element for comparison
        }
        int p1, p2, p3, p4, p0 = INT_MAX;
        p1 = cost[1] + editdist(str1, str2, n, m - 1); //insert
        p2 = cost[2] + editdist(str1, str2, n - 1, m - 1); //replace
        p3 = cost[3] + editdist(str1, str2, n - 1, m); //delete
        p4 = cost[4] + editdist(str1, str2, n - 1, m - 1); //copy
        if (str1[n - 2] == str2[m - 1] && str1[n - 1] == str2[m - 2] && n >= 2 && m >= 2) {

                p0 = cost[0] + editdist(str1, str2, n - 2, m - 2); //twiddle
        }
        return min(p0, min(p1, min(p2, min(p3, p4))));
}
int main() {
        string str1, str2;
        cout << "Enter the 1st string : ";
        cin>>str1;
        cout << "Enter the 2nd string : ";
        cin>>str2;
        cout << "Enter the cost : \n";
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
        cout << "The minimum cost(Recursion): " << editdist(str1, str2, str1.length(), str2.length()) << endl;
        return 0;
}
