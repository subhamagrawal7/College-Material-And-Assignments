#include<bits/stdc++.h>
using namespace std;
string lps(string str, int low, int high) {
        if (low > high) {//base case
                return string("");
        } else if (low == high) {//1 char in string
                return string(1,str[low]);
        } else if (str[low] == str[high]) {
                if (high-1==low) {//checks if size is 2
                        return string(1,str[low]) + string(1,str[high]);
                } else {//start + lps(mid) + end
                        return str[low] + lps(str, low + 1, high - 1) + str[high];
                }
        } else if (lps(str, low + 1, high).length() >= lps(str, low, high - 1).length()) {//checks for largest palindrome subs
                return lps(str, low + 1, high);
        } else {
                return lps(str, low, high - 1);
        }
}
int main() {
        string str;
        cout << "Enter the string(recursive): ";
        cin >> str;
        cout << "The length of the longest palindromic subsequence(recursive)is:" << lps(str, 0, str.length()).length() << endl << "The longest palindromic subsequence(recursive)is:" << lps(str, 0, str.length());
        return 0;
}
