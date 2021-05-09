#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int d, int m, int y)
    {
        this->day = d;
        this->month = m;
        this->year = y;
    }

    friend ostream &operator<<(ostream &output, const Date &D)
    {
        output << "D : " << D.day << " M : " << D.month << " Y :" << D.year;
        return output;
    }

    friend istream &operator>>(istream &input, Date &D)
    {
        input >> D.day >> D.month >> D.year;
        return input;
    }
    bool operator>(const Date &d)
    {
        if (year < d.year)
        {
            return false;
        }
        if (year > d.year)
        {
            return true;
        }

        if (month < d.month)
        {
            return false;
        }
        if (month > d.month)
        {
            return true;
        }

        if (day < d.day)
        {
            return false;
        }
        if (day > d.day)
        {
            return true;
        }
        return false;
    }
    void destroy()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
};

int main()
{
    Date d1(1, 2, 2019);
    Date d2;
    cin >> d2;
    cout << d1 << endl;
    cout << d2 << endl;
    cout << (d2 > d1) << endl;
    d1.destroy();
    cout << d1 << endl;
    return 0;
}