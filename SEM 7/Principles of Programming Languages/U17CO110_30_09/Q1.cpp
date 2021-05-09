#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
    Rectangle()
    {
        width = 10;
        height = 10;
    }

    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }

    double getArea();
    double getPerimeter();
};
double Rectangle::getArea()
{
    return width * height;
}
double Rectangle::getPerimeter()
{
    return 2 * (width + height);
}

int main()
{
    char ch;
    cout << "Do you want to enter width and height(y/n)?: ";
    cin >> ch;
    if (ch == 'y')
    {
        double w, h;
        cout << "Enter width: ";
        cin >> w;
        cout << "Enter height: ";
        cin >> h;
        Rectangle rt(w, h);
        cout << "Area: " << rt.getArea() << endl;
        cout << "Perimeter: " << rt.getPerimeter() << endl;
    }
    else
    {
        Rectangle rt;
        cout << "Area: " << rt.getArea() << endl;
        cout << "Perimeter: " << rt.getPerimeter() << endl;
    }

    return 0;
}