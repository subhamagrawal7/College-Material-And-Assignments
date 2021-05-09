#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    string name;
    string empno;
    Employee()
    {
        cout << "Enter name" << endl;
        cin >> name;
        cout << "Enter employee number" << endl;
        cin >> empno;
    }
    virtual ~Employee()
    {
        cout << "Destroyed base" << endl;
    }
    void salary()
    {
        cout << "The salary of " << name << " is" << endl;
    }
};

class Regular : public Employee
{
public:
    int basic;
    Regular(int basic)
    {
        this->basic = basic;
    }
    ~Regular()
    {
        cout << "Destroyed" << endl;
    }
    void salary()
    {
        Employee::salary();
        cout << 1.4 * basic << endl;
    }
};
class Adhoc : public Employee
{
public:
    int number;
    int wage;
    Adhoc(int wage)
    {
        this->wage = wage;
        this->number = 0;
    }
    ~Adhoc()
    {

        cout << "Destroyed" << endl;
    }
    void days(int n)
    {
        this->number = n;
    }
    void salary()
    {
        Employee::salary();
        cout << number * wage << endl;
    }
};

// main function
int main()
{

    Regular emp1(100);
    Adhoc emp2(10);
    emp2.days(5);
    emp1.salary();
    emp2.salary();
    return 0;
}