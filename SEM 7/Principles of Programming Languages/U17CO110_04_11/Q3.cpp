#include <iostream>
using namespace std;

class time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    time()
    {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    time(int h, int m, int s)
    {
        this->hours = h;
        this->minutes = m;
        this->seconds = s;
    }

    void displayTime24() const
    {
        cout << hours << ":";
        cout << minutes << ":";
        cout << seconds << endl;
    }
    void displayTime12() const
    {
        bool am = false;
        if (hours == 0)
        {
            am = true;
            cout << 12 << ":";
        }
        else if (hours >= 0 && hours <= 12)
        {
            am = true;
            cout << hours << ":";
        }
        else
        {
            am = false;
            cout << hours - 12 << ":";
        }
        cout << minutes << ":";
        cout << seconds;
        if (am)
        {
            cout << "AM" << endl;
        }
        else
        {
            cout << "PM" << endl;
        }
    }

    time addTo(time t1)
    {
        time temp;
        temp.seconds = seconds + t1.seconds;
        temp.minutes = minutes + t1.minutes;
        temp.hours = hours + t1.hours;

        if (temp.seconds >= 60)
        {
            temp.seconds = temp.seconds - 60;
            temp.minutes++;
        }

        if (temp.minutes >= 60)
        {
            temp.minutes = temp.minutes - 60;
            temp.hours++;
        }

        if (temp.hours >= 24)
        {
            temp.hours = temp.hours - 24;
        }

        return temp;
    }
};

int main()
{
    time t1(10, 59, 59);
    time t2(2, 0, 1);
    time t3;

    t3 = t1.addTo(t2);
    cout << "Time t1" << endl;
    t1.displayTime24();
    cout << "Time t2" << endl;
    t2.displayTime24();
    cout << "Time t3" << endl;
    t3.displayTime24();
    t3.displayTime12();

    return 0;
}