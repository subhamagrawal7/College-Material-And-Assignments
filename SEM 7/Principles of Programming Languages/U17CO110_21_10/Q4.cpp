#include <bits/stdc++.h>
using namespace std;

class Distance
{
private:
  int feet;   // 0 to infinite
  int inches; // 0 to 12

public:
  Distance()
  {
    feet = 0;
    inches = 0;
  }
  Distance(int f, int i)
  {
    feet = f;
    inches = i;
  }
  void displayDistance()
  {
    cout << "F: " << feet << " I:" << inches << endl;
  }

  bool operator>(const Distance &d)
  {
    if (feet > d.feet)
    {
      return true;
    }
    if (feet == d.feet && inches > d.inches)
    {
      return true;
    }

    return false;
  }
};

int main()
{
  Distance d1(5, 10), d2(5, 11);

  if (d1 > d2)
  {
    cout << "d1 is greater than d2 " << endl;
  }
  else
  {
    cout << "d2 is greater than d1 " << endl;
  }

  return 0;
}
