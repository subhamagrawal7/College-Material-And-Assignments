#include <bits/stdc++.h>
#include <fstream>
using namespace std;
string encrypt(string text, int s)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        else if (islower(text[i]))
            result += char(int(text[i] + s - 97) % 26 + 97);
        else if (text[i] >= '0' && text[i] <= '9')
            result += char(int(text[i] + s - 48) % 10 + 48);
        else
            result += text[i];
    }
    return result;
}
string decrypt(string text, int s)
{
    string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        if (isupper(text[i]))
        {
            if ((text[i] - (s % 26) - 65) < 0)
                result += 91 + (text[i] - (s % 26) - 65); //Add Z's ASCII value so as to make it circle back
            else
                result += (text[i] - (s % 26) - 65) % 26 + 65;
        }
        else if (islower(text[i]))
        {
            if ((text[i] - (s % 26) - 97) < 0)
                result += 123 + (text[i] - (s % 26) - 97); //Add z's ASCII value so as to make it circle back
            else
                result += (text[i] - (s % 26) - 97) % 26 + 97;
        }
        else if (text[i] >= '0' && text[i] <= '9')
        {
            if ((text[i] - (s % 10) - 48) < 0)
                result += 58 + (text[i] - (s % 10) - 48); // Add 9's ASCII value so as to make it circle back
            else
                result += (text[i] - (s % 10) - 48) % 10 + 48;
        }
        else
            result += text[i];
    }
    return result;
}
void findKeyUsingBruteForce(string plaintext, string ciphertext)
{
    int flag = -1;
    for (int key = 0; key < 26; key++)
    {
        string text = decrypt(ciphertext, key);
        if (plaintext == text)
        {
            flag = key;
            break;
        }
    }
    if (flag != 0)
        cout << "The key is: " << flag;
    return;
}
void findKeyUsingFrequencyAnalysis(string text)
{
    string freq = "etaoinshrdlcumwfgypbvkjxqz"; // according to frequency table
    vector<int> countsOfChar(26);
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
            countsOfChar[text[i] - 'a']++;
        else if (text[i] >= 'A' && text[i] <= 'Z')
            countsOfChar[text[i] + 32]++;
    }
    map<int, char, greater<int>> m;
    for (int i = 0; i < 26; i++)
    {
        if (countsOfChar[i] != 0)
            m[countsOfChar[i]] = i + 'a';
    }
    int j;
    char input;
    map<int, char>::iterator it = m.begin();
    for (j = 0; j < freq.length(); j++)
    {
        int key = (it->second) - freq[j];
        if (key < 0)
            key += 26;
        cout << decrypt(text, key) << endl;
        cout << "Is it correct plain text? Y/N" << endl;
        cin >> input;
        if (input == 'Y')
        {
            cout << "The Encryption key is : " << key;
            return;
        }
        cout << endl;
    }
}
int main()
{
    string text, completeText = "";
    int key, choice;
    cout << "1. Encrypt a string" << endl;
    cout << "2. Decrypt a string" << endl;
    cout << "3. Find Key using Brute force Attack" << endl;
    cout << "4. Find Key using Frequency Analysis Attack" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    ifstream infile;
    infile.open("input1.txt");
    while (!infile.eof())
    {
        getline(infile, text);
        completeText += text + "\n";
    }
    infile.close();

    switch (choice)
    {
    case 1:
    {
        cout << "Enter the key: ";
        cin >> key;
        string encrypted_string = encrypt(completeText, key);
        cout << "Encrypted String: " << encrypted_string << endl;

        ofstream outfile;
        outfile.open("output1.txt");
        outfile << encrypted_string << endl;
        break;
    }

    case 2:
    {
        cout << "Enter the key: ";
        cin >> key;
        string decrypted_string = decrypt(completeText, key);
        cout << "Decrypted String: " << decrypted_string << endl;

        ofstream outfile;
        outfile.open("output1.txt");
        outfile << decrypted_string << endl;
        break;
    }

    case 3:
    {
        ifstream infile2;
        infile2.open("output1.txt"); // contains cipher text
        string text2 = "";
        while (!infile2.eof())
        {
            getline(infile2, text);
            text2 += text + "\n";
        }
        infile2.close();
        findKeyUsingBruteForce(completeText, text2);
        break;
    }

    case 4:
    {
        ifstream infile3;
        infile3.open("freq.txt");
        string text3 = "";
        while (!infile3.eof())
        {
            getline(infile3, text);
            text3 += text + "\n";
        }
        infile3.close();
        findKeyUsingFrequencyAnalysis(text3);
        break;
    }
    default:
        cout << "You have entered wrong choice!!" << endl;
        break;
    }
    return 0;
}
