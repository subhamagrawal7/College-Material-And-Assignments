#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string encryption(string message, string key)
{
    multimap<int, int> key_index;
    for (int i = 0; i < key.length(); i++)
        key_index.insert(pair<int, int>(key[i], i));
    int col = key.length();
    int row = (message.length()) / (col);
    if (message.length() % col)
        row++;
    char matrix[row][col];
    for (int i = 0, k = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++, k++)
        {
            if (k >= message.length())
                matrix[i][j] = '_';
            else
                matrix[i][j] = message[k];
        }
    }

    string cipher;
    multimap<int, int>::iterator it;
    for (it = key_index.begin(); it != key_index.end(); it++)
    {
        int j = it->second;
        for (int i = 0; i < row; i++)
        {
            cipher += matrix[i][j];
        }
    }
    return cipher;
}
string decryption(string cipher, string key)
{
    multimap<int, int> key_index;
    for (int i = 0; i < key.length(); i++)
        key_index.insert(pair<int, int>(key[i], i));
    int col = key.length();
    int row = (cipher.length()) / (col);
    if (cipher.length() % col)
        row++;
    char matrix[row][col];
    multimap<int, int>::iterator it;
    int k = 0;
    for (it = key_index.begin(); it != key_index.end(); it++)
    {
        int j = it->second;
        for (int i = 0; i < row; i++)
            matrix[i][j] = cipher[k++];
    }
    string message;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '_')
                return message;
            message += matrix[i][j];
        }
    }
    return message;
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
            string data = "", line;
            string key;
            ifstream infile;
            infile.open("input1.txt");
            while (!infile.eof())
            {
                getline(infile, line);
                data += line;
            }
            infile.close();
            cout << "String: " << data << endl;
            cout << "Enter the key: ";
            cin >> key;

            cout << "**********************************************************\n";
            cout << "Cipher Text : " << encryption(data, key) << endl;
            ofstream outfile;
            outfile.open("output1.txt");
            outfile << encryption(data, key);
            outfile.close();
            break;
        }
        case 2:
        {
            string data = "", line;
            string key;
            ifstream infile;
            infile.open("output1.txt");
            while (!infile.eof())
            {
                getline(infile, line);
                data += line;
            }
            infile.close();
            cout << "String: " << data << endl;
            cout << "Enter the key: ";
            cin >> key;

            cout << "**********************************************************\n";
            cout << "Plain Text : " << decryption(data, key) << endl;
            ofstream outfile;
            outfile.open("input1.txt");
            outfile << decryption(data, key);
            outfile.close();

            break;
        }
        case 3:
        {
            run = false;
            cout << "Thanks\n";
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
