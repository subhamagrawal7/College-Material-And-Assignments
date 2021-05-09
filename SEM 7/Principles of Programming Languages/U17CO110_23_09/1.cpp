#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

double pi = 3.14159265359;

using namespace std;
class Coordinates
{
	double radius;
    double angle;


  double getx()
    {

      return radius*cos(pi*angle/180);
    }
  double gety()
    {
      return radius*sin(pi*angle/180);
    }
   Coordinates()
   {
       radius=0.0;angle=0.0;
   }
public:
   Coordinates(double r,double a)
    {
      radius = r;
      angle = a;
    }

   void display()
    {
        double x = getx();
        double y = gety();

       cout<<"\n X coordinate : "<<x;
	   cout<<"\n Y coordinate : "<<y;
    }
};

int main()
{
	double r,a;
    cout<<"********POLAR COORDINATE SYSTEM********\n";
	cout<<"\n Enter the radius :  ";
	cin>>r;
	cout<<"\n Enter the angle (in degree) :  ";
	cin>>a;

    Coordinates cod(r,a);
    cout<<endl;
    cout<<"*****RECTANGULAR COORDINATE SYSTEM*****\n";

    cod.display();

    return 0;
}
