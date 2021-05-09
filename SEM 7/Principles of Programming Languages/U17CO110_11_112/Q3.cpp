#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c1, c2;

    ifstream inputFileName;
    ofstream outputFileName;
    inputFileName.open("sample.txt");
    outputFileName.open("Q3_output.txt");
    inputFileName >> noskipws;

    while (!inputFileName.eof())
    {
        inputFileName.get(c1);
        if (!inputFileName)
            break;
        if (c1 >= 'a' && c1 <= 'z')
            outputFileName << (char)(c1 - 32);
        else if (c1 >= 'A' && c1 <= 'Z')
            outputFileName << (char)(c1 + 32);
        else
            outputFileName << c1;
    }

    outputFileName.close();
    inputFileName.close();

    cout << "SUCCESSFULLY EXECUTED!!!";
    return 0;
}
