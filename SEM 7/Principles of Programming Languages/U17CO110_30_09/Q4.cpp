#include <bits/stdc++.h>

using namespace std;

class Student
{
private:
    int enrNo;
    string name;
    int grades[6];
    double spi;

public:
    void getData()
    {
        cout << "Enter Enrollment No: " << endl;
        cin >> enrNo;
        cout << "Enter Name: " << endl;
        cin >> name;
        while (name.length() > 20)
        {
            cout << "max 20 chars.\n";
            cout << "Enter Name: " << endl;
            cin >> name;
        }
        cout << "Enter grade space separated: " << endl;
        for (int &grade : grades)
            cin >> grade;
        getSPI();
    }

    void getSPI()
    {
        int tot = 0;
        for (int &grade : grades)
            tot += grade;
        spi = tot / 6.0;
    }

    void display()
    {
        cout << "EnrollmentNo: " << enrNo << '\n';
        cout << "Name: " << name << '\n';
        cout << "SPI: " << spi << "\n";
        cout << "----------------------------------------------------" << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the no. of students: ";
    cin >> n;
    vector<Student> stud(n);
    for (Student &x : stud)
    {
        x.getData();
    }

    cout << "Results: \n";
    for (Student &x : stud)
        x.display();
    return 0;
}
