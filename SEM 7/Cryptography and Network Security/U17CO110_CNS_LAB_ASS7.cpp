#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;
string prepare(string key, int n)
{
    int m = key.length();
    string f_key = "";
    for (int i = 0; i < n; i++)
        f_key += key[i % m];
    return f_key;
}
string encryption(string message, string key)
{
    string cipher = "";
    int n = message.length();
    string f_key = prepare(key, n);
    cout << "Prepared Key: " << f_key << endl;
    for (int i = 0; i < n; i++)
    {
        cipher += (((message[i] - 'A') + (f_key[i] - 'A')) % 26 + 'A');
    }
    return cipher;
}
string decryption(string message, string key)
{

    string plain = "";
    int n = message.length();
    string f_key = prepare(key, n);
    cout << "Prepared Key: " << f_key << endl;
    for (int i = 0; i < n; i++)
    {
        plain += ((message[i] - f_key[i] + 26) % 26 + 'A');
    }
    return plain;
}

int main()
{
    bool run = true;
    while (run)
    {
        cout << "**********************************************************\n";
        cout << "Press 1 for encryption , 2 for decryption and 3 for exit\n";
        int input;
        cin >> input;
        cout << "**********************************************************\n";
        switch (input)
        {
        case 1:
        {

            string data;
            cout << "Enter Plain Text: ";
            cin >> data;
            string key;
            cout << "Enter key: ";
            cin >> key;
            cout << "**********************************************************\n";
            transform(data.begin(), data.end(), data.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            string cipher = encryption(data, key);
            cout << "Cipher Text: " << cipher << endl;
            break;
        }
        case 2:
        {
            string data;
            cout << "Enter Cipher Text: ";
            cin >> data;
            string key;
            cout << "Enter key: ";
            cin >> key;
            cout << "**********************************************************\n";
            transform(data.begin(), data.end(), data.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            string plain = decryption(data, key);
            cout << "Plain Text : " << plain << endl;
            break;
        }
        case 3:
        {
            run = false;
            cout << "Thanks for running the program\n";
            cout << "**********************************************************\n";
            break;
        }
        default:
        {
            cout << "**********************************************************\n";
            cout << "Wrong input!!! Enter Again.\n";
        }
        }
    }
}
