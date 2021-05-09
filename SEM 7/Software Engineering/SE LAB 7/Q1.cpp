#include <bits/stdc++.h>
using namespace std;

int main()
{
    float m;
    cout << "Enter marks of student: ";
    cin >> m;

    int marksofstud = round(m);
    string grade;

    if (marksofstud >= 90)
        grade = "A+";
    else if (marksofstud >= 80)
        grade = "A";
    else if (marksofstud >= 70)
        grade = "B";
    else if (marksofstud >= 60)
        grade = "C";
    else if (marksofstud >= 50)
        grade = "D";
    else
        grade = "F";
    cout << "Grade: " << grade << endl;
    return 0;
}
