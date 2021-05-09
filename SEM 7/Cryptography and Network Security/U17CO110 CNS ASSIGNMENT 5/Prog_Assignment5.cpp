#include <bits/stdc++.h>
#include <string>
#include <fstream>

using namespace std;

string encryption(string message, int a, int b)
{
    string cipher = "";
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] != ' ')
            cipher = cipher + (char)((((a * (message[i] - 'A')) + b) % 26) + 'A');
        else
            cipher += message[i];
    }
    return cipher;
}

string decryption(string cipher, int a, int b)
{

    string plain = "";
    int a_inv = 0;
    for (int i = 0; i < 26; i++)
    {
        if (((a * i) % 26) == 1)
        {
            a_inv = i;
            break;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')
        {
            int temp = cipher[i] - 'A' - b;
            if (temp < 0)
                temp += 26;
            plain += (char)(((a_inv * temp) % 26) + 'A');
        }
        else
            plain += cipher[i];
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
            int a, b;
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
            cout << "Enter a and b: ";
            cin >> a >> b;
            if (__gcd(a, 26) != 1)
            {
                cout << "Enter valid value of a\n";
                goto again;
            }
            cout << "**********************************************************\n";
            string cipher = encryption(data, a, b);
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
            int a, b;
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
            cout << "Enter a and b: ";
            cin >> a >> b;
            if (__gcd(a, 26) != 1)
            {
                cout << "Enter valid value of a\n";
                goto again1;
            }
            cout << "**********************************************************\n";
            string plain = decryption(data, a, b);
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
