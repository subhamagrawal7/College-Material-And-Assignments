#include <bits/stdc++.h>
using namespace std;

class License
{

    string LNo, Name, Address;

public:
    License() = default;

    License(string lNo, string name, string address)
    {
        this->LNo = move(lNo);
        this->Name = name;
        this->Address = move(address);
    }
};

int main()
{

    int n;
    string lno, name, address;
    ofstream outputFileName;
    outputFileName.open("License.txt");

    cout << ".....INITIAL CREATING FILE.....\n";
    cout << "Enter total number of license: " << endl;
    cin >> n;

    // CREATING THE FILE
    vector<License> licenseList;
    for (int i = 0; i < n; i++)
    {

        cout << "Enter License No: " << endl;
        cin >> lno;

        cout << "Enter Name: " << endl;
        cin.ignore();
        getline(cin, name);

        cout << "Enter Address: " << endl;
        getline(cin, address);

        outputFileName << lno << "\n";
        outputFileName << name << "\n";
        outputFileName << address << "\n";
        licenseList.emplace_back(License(lno, name, address));
    }

    outputFileName.close();

    // SEARCH FOR NAME BASED ON LICENSE NUMBER

    cout << ".....SEARCH FOR NAME BASED ON LICENSE NUMBER.....\n";
    string targetLicNo;
    bool isFound = false;
    cout << "Enter License No: ";
    cin >> targetLicNo;

    ifstream inputFileName;
    inputFileName.open("License.txt");

    while (getline(inputFileName, lno) && getline(inputFileName, name) && getline(inputFileName, address))
    {
        if (lno == targetLicNo)
        {
            cout << "MATCH FOUND!! NAME OF LICENSE HOLDER: " << name << endl;
            isFound = true;
            break;
        }
    }
    if (!isFound)
        cout << "Sorry no match found\n";
    inputFileName.close();

    // SEARCING BASED ON NAME OF PERSON
    cout << ".....SEARCH FOR LICENSE NUMBER BASED ON NAME.....\n";
    inputFileName.open("License.txt");
    isFound = false;
    string targetName;
    cout << "Enter Name of License Holder: ";
    cin.ignore();
    getline(cin, targetName);
    while (getline(inputFileName, lno) && getline(inputFileName, name) && getline(inputFileName, address))
    {
        if (name == targetName)
        {
            cout << "MATCH FOUND!!! LICENSE NUMBER : " << lno << "\n";
            isFound = true;
        }
    }
    if (!isFound)
        cout << "Sorry no match found\n";
    inputFileName.close();

    // UPDATING NAME BASED ON LICENSE NUMBER
    cout << ".....UPDATING NAME BASED ON LICENSE NUMBER.....\n";
    string NewName, Lno;
    outputFileName.open("temp.txt");
    inputFileName.open("License.txt");

    cout << "Enter License no: ";
    getline(cin, Lno);
    cout << "Enter New Name: ";
    getline(cin, NewName);
    while (getline(inputFileName, lno) && getline(inputFileName, name) && getline(inputFileName, address))
    {
        outputFileName << lno << "\n";
        outputFileName << (lno == Lno ? NewName : name) << "\n";
        outputFileName << address << "\n";
    }

    outputFileName.close();
    inputFileName.close();

    if (remove(R"(License.txt)") != 0)
    {
        cout << "Error deleting file\n";
    };

    rename(R"(temp.txt)", R"(License.txt)");
    return 0;
}
