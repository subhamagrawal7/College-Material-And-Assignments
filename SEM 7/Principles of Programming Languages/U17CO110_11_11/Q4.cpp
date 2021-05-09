#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c1, c2;

    ifstream inputFileName;
    ofstream outputFileName;
    inputFileName.open("sample.txt");
    outputFileName.open("Q4_output.txt");
    inputFileName >> noskipws;

    while (!inputFileName.eof())
    {
        inputFileName.get(c1);
        if (!inputFileName)
            break;
        if (!(c1 >= '0' && c1 <= '9'))
            outputFileName << c1;
    }

    outputFileName.close();
    inputFileName.close();

    cout << "SUCCESSFULLY EXECUTED!!!";
    return 0;
}
