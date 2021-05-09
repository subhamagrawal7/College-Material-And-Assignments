#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<vector<int>> prepare(string s, int n)
{
    vector<vector<int>> k(n, vector<int>(n));
    for (int i = 0; i < n * n; ++i)
    {
        k[i / n][i % n] = (s[i] - 'A') % 26;
    }
    return k;
}

string encryption(string message, string key)
{
    int n = sqrt(key.length());
    string cipher = "";
    vector<vector<int>> key_matrix = prepare(key, n);
    int len = message.length();
    if (len % n != 0)
    {
        for (int i = 1; i <= n - len % n; i++)
            message += 'Z';
    }
    int m = message.length() / n;
    for (int k = 0; k < m * n; k += n)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += key_matrix[i][j] * (message[k + j] - 'A');
            }
            cipher += ((sum % 26) + 'A');
        }
    }

    return cipher;
}
string decryption(string message, string key)
{

    string plain = "";
    int n = sqrt(key.length());
    vector<vector<int>> key_matrix = prepare(key, n);
    //vector< vector< float > > key_matrix=inv_matrix(key_matrix1,n);
    int len = message.length();
    if (len % n != 0)
    {
        for (int i = 1; i <= n - len % n; i++)
            message += 'Z';
    }
    int m = message.length() / n;
    for (int k = 0; k < m * n; k += n)
    {
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += key_matrix[i][j] * (message[k + j] - 'A');
            }

            plain += (char)(fmod(sum, 26) + 65);
        }
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
            string data = "", line = "";
            ifstream infile;
            infile.open("input1.txt");
            while (!infile.eof())
            {
                getline(infile, line);
                data += line;
            }
            infile.close();
            cout << "String: " << data << endl;
        again:
            string key;
            cout << "Enter key: ";
            cin >> key;
            int x = key.length();
            long double sr = sqrt(x);
            if ((sr - floor(sr)) != 0)
            {
                cout << "Enter valid key(Key length needs to be perfect square)\n";
                goto again;
            }
            cout << "**********************************************************\n";
            transform(data.begin(), data.end(), data.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            string cipher = encryption(data, key);
            cout << "Cipher Text: " << cipher << endl;
            ofstream outfile;
            outfile.open("output1.txt");
            outfile << cipher;
            outfile.close();
            break;
        }
        case 2:
        {
            string data = "", line;
            ifstream infile;
            infile.open("output1.txt");
            while (!infile.eof())
            {
                getline(infile, line);
                data += line;
            }
            infile.close();
            cout << "String: " << data << endl;
        again1:
            string key;
            cout << "Enter key: ";
            cin >> key;
            int x = key.length();
            long double sr = sqrt(x);
            if ((sr - floor(sr)) != 0)
            {
                cout << "Enter valid key(Key length needs to be perfect square)\n";
                goto again1;
            }
            cout << "**********************************************************\n";
            transform(data.begin(), data.end(), data.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            string plain = decryption(data, key);
            cout << "Plain Text : " << plain << endl;
            ofstream outfile;
            outfile.open("input1.txt");
            outfile << plain;
            outfile.close();

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

//key-> GYBNQKURP
//key_inv -> IFKVIVVMI
