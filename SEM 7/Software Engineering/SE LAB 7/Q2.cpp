#include <bits/stdc++.h>
using namespace std;

void insuranceCoverageCalculator()
{
    int base;
    cout << "Enter BASE PAY for the car" << endl;
    cin >> base;
    cout << "Enter your AGE" << endl;
    int age;
    cin >> age;
    char ch, g;
    cout << "Enter gender: m/f" << endl;
    cin >> g;
    cout << "For Business ? Y or N" << endl;
    cin >> ch;

    double pay;
    if (age > 60)
    {
        pay = 0.9 * base;
    }
    if (age < 25 && g == 'm')
    {
        pay = 1.5 * base;
    }
    if (ch == 'Y')
    {
        pay = 1.2 * pay;
    }
    cout << "You need to pay $ " << pay << " for the insurance coverage.." << endl;
}

int main()
{
    insuranceCoverageCalculator();
    return 0;
}
