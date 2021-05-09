#include<iostream>
using namespace std;

class Time
{
private:
    int hours;   // 0 to 23
    int minutes; // 0 to 59

public:
    Time()
    {
        hours = 0;
        minutes = 0;
    }
    Time(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    void displayTime()
    {
        cout << "H: " << hours << " M:" << minutes << endl;
    }

    Time operator++()
    {
        ++minutes; // increment this object
        if (minutes >= 60)
        {
            ++hours;
            minutes -= 60;
        }
        return Time(hours, minutes);
    }

    Time operator++(int)
    {
        Time T(hours, minutes);
        ++minutes;

        if (minutes >= 60)
        {
            ++hours;
            minutes -= 60;
        }
        return T;
    }

    Time operator--()
    {
        --minutes; // increment this object
        if (minutes < 0)
        {
            --hours;
            minutes += 60;
        }
        return Time(hours, minutes);
    }

    Time operator--(int)
    {
        Time T(hours, minutes);
        --minutes;

        if (minutes < 0)
        {
            --hours;
            minutes += 60;
        }
        return T;
    }
};

int main()
{
    Time T1(10, 59), T2(11, 40);

    ++T1;
    T1.displayTime();
    ++T1;
    T1.displayTime();

    --T1;
    T1.displayTime();
    --T1;
    T1.displayTime();

    T2++;
    T2.displayTime();
    T2++;
    T2.displayTime();

    T2--;
    T2.displayTime();
    T2--;
    T2.displayTime();
    return 0;
}