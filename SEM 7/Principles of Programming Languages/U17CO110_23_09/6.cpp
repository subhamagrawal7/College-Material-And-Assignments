#include <iostream>
using namespace std;


class AirIndia {
private:
    int flightNo;
    string destination;
    float distance;
    float fuel;

    void calcFuel()
    {
    	if(distance <= 1000)
    	{
    		fuel = 500;
		}

		else if(distance > 1000 && distance <=2000)
		{
			fuel = 1100;
		}

		else if (distance > 2000)
		{
			fuel = 2200;
		}
	}

public:
    void feedInfo()
    {
    	cout<<"\n ---------ENTER THE FOLLOWING INFORMATION------------ \n";
    	cout<<"Enter Flight Number: ";
    	cin>>flightNo;
    	cout<<"Enter Destination: ";
    	cin>>destination;
    	cout<<"Enter Distance: ";
    	cin>>distance;
    	calcFuel();
	}

	void showInfo()
	{
        cout<<"\n ********************************************************\n";
    	cout<<"Flight Number : "<<flightNo;
    	cout<<"\n Destination : "<<destination;
    	cout<<"\n Distance : "<<distance;
    	cout<<"\n Fuel : "<<fuel;

    }
};

int main()
{
    AirIndia airMem[2];

    int a, ch, i;
    for (i = 0; i < 2; i++) {
    	airMem[i].feedInfo();
            }
     for (i = 0; i < 2; i++) {

        airMem[i].showInfo();
    }

    return 0;
}

