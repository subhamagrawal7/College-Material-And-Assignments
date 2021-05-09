#include <bits/stdc++.h>
using namespace std;

class Report
{
private:
    int enrol_no;
    string name;
    float marks[5];
    float average;

public:
    void READINFO()
    {
        cout << "Enter 4-digit enrollment no.: ";
        cin >> enrol_no;
        cin.ignore();
        cout << "Enter name: \n";
        getline(cin, name);
        while (name.length() > 20)
        {
            cout << "max 20 chars.\n";
            cout << "Enter Name: " << endl;
            cin.ignore();
            getline(cin, name);
        }
        cout << "Enter marks in 5 subjects: " << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }
    void GETAVG()
    {
        float sum = 0.0;
        for (int i = 0; i < 5; i++)
        {
            sum += marks[i];
        }
        average = sum / 5.0;
    }
    void DISPLAYINFO()
    {
        cout << "--------------------------------------" << endl;
        cout << "Enrollment No.: " << enrol_no << endl;
        cout << "Name: " << name << endl;
        cout << "Marks in 5 subjects:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << endl;
        }
        cout << "Average: " << average << endl;
        cout << "--------------------------------------" << endl;
    }
};

int main()
{
    Report re;
    re.READINFO();
    re.GETAVG();
    re.DISPLAYINFO();

    return 0;
}