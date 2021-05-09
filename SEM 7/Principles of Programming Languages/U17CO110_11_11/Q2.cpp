#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c1, c2;

    ifstream inputFileName;
    ofstream outputFileName;
    inputFileName.open("sample.txt");
    outputFileName.open("Q2_output.txt");
    inputFileName >> noskipws;

    while (!inputFileName.eof())
    {
        inputFileName.get(c1);
        if (!inputFileName)
            break;

        if (c1 != ' ')
            outputFileName << c1;
        else
        {
            inputFileName.get(c2);
            if (!inputFileName)
            {
                outputFileName << c1;
                break;
            }
            else
            {
                if (c2 != ' ')
                    outputFileName << c1 << c2;
                else
                    outputFileName << c1;
            }
        }
    }

    outputFileName.close();
    inputFileName.close();

    cout << "SUCCESSFULLY EXECUTED!!!";
    return 0;
}
