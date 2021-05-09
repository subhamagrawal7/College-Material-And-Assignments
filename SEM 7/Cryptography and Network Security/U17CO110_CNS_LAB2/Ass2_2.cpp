#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string encryption(string message, int key)
{
    int row = key;
    int col = message.length();
    vector<vector<char>> matrix(row, vector<char>(col, '_'));
    bool down = false;
    int j = 0;
    for (int i = 0; i < col; i++)
    {
        if (j == 0 || j == row - 1)
            down = !down;
        matrix[j][i] = message[i];
        down ? j++ : j--;
    }
    string cipher;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != '_')
                cipher += matrix[i][j];
        }
    }
    return cipher;
}
string decryption(string cipher, int key)
{
    int row = key;
    int col = cipher.length();
    vector<vector<char>> matrix(row, vector<char>(col, '_'));
    bool down = false;
    int j = 0;
    for (int i = 0; i < col; i++)
    {
        if (j == 0 || j == row - 1)
            down = !down;
        matrix[j][i] = '*';
        down ? j++ : j--;
    }
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (matrix[i][j] == '*' && k < col)
            {
                matrix[i][j] = cipher[k++];
            }
        }
    }
    j = 0;
    down = false;
    string plain;
    for (int i = 0; i < col; i++)
    {
        if (j == 0 || j == row - 1)
            down = !down;
        plain += matrix[j][i];
        down ? j++ : j--;
    }
    return plain;

    return "YEs";
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
            int key;
            ifstream infile;
            infile.open("input2.txt");
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
            outfile.open("output2.txt");
            outfile << encryption(data, key);
            outfile.close();

            break;
        }
        case 2:
        {
            string data = "", line;
            int key;
            ifstream infile;
            infile.open("output2.txt");
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
            outfile.open("input2.txt");
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
