#include <iostream>
using namespace std;

class Batman {
private:
    int bcode;
    int innings,notout,runs;
    string bname;
    float batavg;
    void calcavg()
    {
    	batavg = runs/(innings - notout);
	}

public:
    void readdata()
    {
    	cout<<"\nEnter the Bcode: ";
    	cin>>bcode;
    	cin.ignore();
        cout << "Enter Name: " ;
        getline(cin, bname);
        while (bname.length() > 20) {
        cout<<"Max Characters 20!!\n";
        cout << "Enter Name(max 20 chars): ";
        getline(cin, bname);
        }
    	cout<<"Enter the innings: ";
    	cin>>innings;
    	cout<<"Enter the Notout: ";
    	cin>>notout;
    	cout<<"Enter the runs: ";
    	cin>>runs;

    	calcavg();
	}

	void display()
	{
		cout<<"\n ********************************************************\n";
    	cout<<"\n The Bcode: "<<bcode;
    	cout<<"\n Name of Batsman: "<<bname;
    	cout<<"\n The inning: "<<innings;
    	cout<<"\n The Notout: "<<notout;
    	cout<<"\n The runs: "<<runs;
    	cout<<"\n Batting average: "<<batavg;


	}
};


int main()
{
    Batman batman[2];

    int a, ch, i;
    for (i = 0; i < 2; i++) {
    	batman[i].readdata();
    }

	for(i=0;i< 2;i++)
	{
		batman[i].display();
	}


    return 0;
}

