#include <iostream>
using namespace std;

class Student {
private:
    char enrollmentNo[8];
    float eng;
    float math;
    float science;
    string name;
    float total;

public:
    void getData()
    {
        cout <<"\nEnter Enrollment Number: ";
        cin >> enrollmentNo;
        cin.ignore();
        cout << "Enter Name: " ;
        getline(cin, name);
        while (name.length() > 20) {
            cout<<"Max Characters 20!!\n";
            cout << "Enter Name(max 20 chars): ";
            getline(cin, name);
        }
        cout <<"Enter the marks in English: ";
        cin >> eng;
        cout <<"Enter the marks in Maths: ";
        cin>> math;
        cout <<"Enter the marks in Science: ";
        cin >> science;
    }
    void cTotal()
    {
        total = (eng + math + science);
        cout<<" "<<total;
    }
    void displayData()
    {
    	cout<<"\n ********************************************************\n";
        cout<<" Student Enrollment Number : "<<enrollmentNo<<endl;
        cout<<" Student Name : "<<name<<endl;
        cout<<" Student's Score in : "<<endl;
        cout<<" English : "<<eng<<endl;
        cout<<" Mathematics : "<<math<<endl;
        cout<<" Science : "<<science<<endl;


    }

};


int main()
{
    Student stud[5];

    int a, ch, i;
    char found[8];
    for (i = 0; i <= 4; i++) {
    	cout<<"---------------Student "<<i+1<<"---------------";
        stud[i].getData();
    }

    while(1) {
        cout<<"\n***************************************************\n";
        cout << "Press 1:Display Data ,2:Calculate Total  ,3:Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            for (i = 0; i <= 4; i++) {
                stud[i].displayData();
            }
            break;
        case 2:
            cout<<"\n Total marks obtained are as follows: ";
            for(i=0;i<5;i++)
            {
            	cout<<"\n Student "<<i+1<<" : ";
            	stud[i].cTotal();
			}
			break;
        case 3: cout<<"\n Thanks!!!";
            goto last;
		default:
            cout << "Invalid Option" << endl;
        }
    }
    last:
    return 0;
}

