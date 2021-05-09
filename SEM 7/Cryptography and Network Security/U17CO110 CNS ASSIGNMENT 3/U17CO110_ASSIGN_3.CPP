#include <bits/stdc++.h>
#include <string.h>
#include <fstream>

using namespace std;

char keys[5][5];
set<char> k;

void index(int arr[], char a, char b)
{
    int cnt = 0;
    if (a == 'J')
        a = 'I';
    if (b == 'J')
        b = 'I';
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keys[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
                cnt++;
            }
            if (keys[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
                cnt++;
            }
            if (cnt == 2)
                return;
        }
    }
}

void key_matrix(string key)
{
    k.clear();
    int z = 0;
    char ch = 'A';
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
        again:
            if (z < key.length())
            {
                if (k.find(key[z]) == k.end())
                {
                    k.insert(key[z]);
                    keys[i][j] = key[z++];
                }
                else
                {
                    z++;
                    goto again;
                }
            }
            else
            {
                while (1)
                {
                    if (ch == 'J')
                        ;
                    else if (k.find(ch) == k.end())
                    {
                        keys[i][j] = ch;
                        ch++;
                        break;
                    }
                    ch++;
                }
            }
            cout << keys[i][j] << " ";
        }
        cout << endl;
    }
}
string encryption(string message, string key)
{
    key_matrix(key);
    int len = message.length();
    int ind[4];
    string cipher;
    char a, b;
    string temp;

    for (int i = 0; i < len; i++)
    {
        while (!isalpha(message[i]))
        {
            if (i == len)
                goto done;
            cipher += message[i++];
        }
        a = message[i++];
        temp = "";
        while (!isalpha(message[i]) && i != len) // If first is alphabet but not second
            temp += message[i++];
        if (i == len)
            message += 'Z';
        b = message[i];
        index(ind, a, b);
        if (ind[0] == ind[2]) // present in same row
        {
            cipher += (keys[ind[0]][(ind[1] + 1) % 5]);
            cipher += temp;
            cipher += (keys[ind[2]][(ind[3] + 1) % 5]);
        }
        else if (ind[1] == ind[3]) // present in same column
        {
            cipher += (keys[(ind[0] + 1) % 5][ind[1]]);
            cipher += temp;
            cipher += (keys[(ind[2] + 1) % 5][ind[3]]);
        }
        else
        {
            cipher += keys[ind[0]][ind[3]]; // column of second letter
            cipher += temp;
            cipher += keys[ind[2]][ind[1]]; // column of first letter
        }
    }
done:
    return cipher;
}

string decryption(string message, string key)
{
    key_matrix(key);
    int len = message.length();
    int ind[4];
    string plain, temp;
    char a, b;
    for (int i = 0; i < len; i++)
    {
        while (!isalpha(message[i]))
        {
            if (i == len)
                goto done2;
            plain += message[i++];
        }
        a = message[i++];
        temp = "";
        while (!isalpha(message[i]))
            temp += message[i++];
        b = message[i];
        index(ind, a, b);
        if (ind[0] == ind[2]) // present in same row
        {
            plain += (keys[ind[0]][(ind[1] - 1) < 0 ? (ind[1] + 4) : (ind[1] - 1)]);
            plain += temp;
            plain += (keys[ind[2]][(ind[3] - 1) < 0 ? (ind[3] + 4) : (ind[3] - 1)]);
        }
        else if (ind[1] == ind[3]) // present in same column
        {
            plain += (keys[(ind[0] - 1) < 0 ? (ind[0] + 4) : (ind[0] - 1)][ind[1]]);
            plain += temp;
            plain += (keys[(ind[2] - 1) < 0 ? (ind[2] + 4) : (ind[2] - 1)][ind[3]]);
        }
        else
        {
            plain += keys[ind[0]][ind[3]]; // column of second letter
            plain += temp;
            plain += keys[ind[2]][ind[1]]; // column of first letter
        }
    }
done2:
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
            // convert everything to upper case
            transform(data.begin(), data.end(), data.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            cout << "**********************************************************\n";
            string cipher = encryption(data, key);
            cout << "Cipher Text : " << cipher << endl;

            ofstream outfile;
            outfile.open("output1.txt");
            outfile << cipher;
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
            transform(data.begin(), data.end(), data.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            cout << "**********************************************************\n";
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
