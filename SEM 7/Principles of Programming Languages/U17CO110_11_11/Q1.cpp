#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    string rollNo;
    float cgpa;
    char c;

    cout << "Enter student name: ";
    getline(cin, name);
    cin.ignore();
    cout << "Enter student rollNo: ";
    getline(cin, rollNo);
    cout << "Enter student cgpa: ";
    cin >> cgpa;

    ofstream outputFileName;
    outputFileName.open("student1.txt");

    outputFileName << "Name: " << name << " ";
    outputFileName << "RollNo: " << rollNo << " ";
    outputFileName << "CGPA: " << cgpa << endl;
    outputFileName.close();

    ifstream inputFileName;
    inputFileName.open("student1.txt");
    outputFileName.open("student2.txt");
    inputFileName >> noskipws;

    while (inputFileName)
    {
        inputFileName >> c;
        outputFileName << c;
    }

    outputFileName.close();
    inputFileName.close();

    return 0;
}
