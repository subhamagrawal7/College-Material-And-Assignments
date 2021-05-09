#include<bits/stdc++.h>
using namespace std;
int cost[5] = { 1, 1, 1, 1, 1};
bool check(string str1, string str2, int n, int m, string tmp) {
        int ptr1 = 0, ptr2 = 0;
        char ch;
        for (int i = 0; i < tmp.length() && ptr1 < n && ptr2 < m; i++) {
                ch = tmp[i];
                if (ch == 'C') {
                        if (str1[ptr1] == str2[ptr2]) {
                                ptr1++;
                                ptr2++;
                        }
                } else if (ch == 'R') {
                        ptr1++;
                        ptr2++;
                } else if (ch == 'D') {
                        ptr1++;
                } else if (ch == 'I') {
                        ptr2++;
                } else if (ch == 'T') {
                        if (ptr1 <= n - 2 && ptr2 <= m - 2) {
                                if (str1[ptr1] == str2[ptr2 + 1] && str1[ptr2] == str2[ptr1 + 1]) {
                                        ptr1 += 2;
                                        ptr2 += 2;
                                }
                        }
                } else {
                        if (ptr2 == m) {
                                ptr1 = n;
                                break;
                        }
                }
        }
        if (ptr1 == n && ptr2 == m) {
                return true;
        } else {
                return false;
        }
}
int editdist(string str1, string str2) {
        long int lmt = pow(6, str1.length() + str2.length()) - 1;
        int res = INT_MAX;
        for (int i = 0; i <= lmt; i++) {
                string tmp;
                int nums = i;
                for (int j = 0; j < max(str2.length(), str1.length()); j++) {
                        tmp = to_string(nums % 6) + tmp;
                        nums /= 6;
                }
                bool fl = false;
                for (int k = 0; k < tmp.length(); k++) {
                        if (tmp[k] == '0') {
                                fl = true;
                                break;
                        }
                }
                if (fl != false) {
                        continue;
                }
                string tmp2;
                for (int k = 0; k < tmp.length(); k++) {
                        if (tmp[k] == '1') {
                                tmp2 += 'C';
                        } else if (tmp[k] == '2') {
                                tmp2 += 'R';
                        } else if (tmp[k] == '3') {
                                tmp2 += 'D';
                        } else if (tmp[k] == '4') {
                                tmp2 += 'I';
                        } else if (tmp[k] == '5') {
                                tmp2 += 'T';
                        }
                }
                bool is_possible = check(str1, str2, str1.length(), str2.length(), tmp2);
                if (is_possible) {
                        int cost1 = 0;
                        for (int k = 0; k < tmp2.length(); k++) {
                                if (tmp2[k] == 'C')
                                        cost1 += cost[4];
                                else if (tmp2[k] == 'R')
                                        cost1 += cost[2];
                                else if (tmp2[k] == 'I')
                                        cost1 += cost[1];
                                else if (tmp2[k] == 'T')
                                        cost1 += cost[0];
                                else if (tmp2[k] == 'D')
                                        cost1 += cost[3];
                        }
                        if (cost1 < res) {
                                res = cost1;
                        }
                }
        }
        return res;
}
int main() {
        string str1, str2;
        cout << "Enter the 1st string : ";
        cin >> str1;
        cout << "Enter the 2nd string : ";
        cin >> str2;
        cout << "Enter the cost of: \n";
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
        cout << "The minimum cost: " << editdist(str1, str2) << endl;
        return 0;
}

