
#include <bits/stdc++.h>
using namespace std;
#define k 2
class Student {
public:
        int entryno, rollno;
        string name;

        void getData() {
                cout << "Enter RollNo: ";
                cin >> rollno;
                cout << "Enter Name: ";
                cin >> name;
        }

        void DisplayBase(){
                cout << "------------------------------------------------\n";
                cout << "EntryNo: " << entryno << "\n";
                cout << "RollNo: " << rollno << "\n";
                cout << "Name: " << name << "\n";
        }
};

class Science : public Student {
private:
        int Physics, Chemistry, Mathematics;
public:
        void getDataScience() {
                getData();
                entryno = 1;
                cout << "Enter Physics Marks: ";
                cin >> Physics;
                cout << "Enter Chemistry Marks: ";
                cin >> Chemistry;
                cout << "Enter Mathematics Marks: ";
                cin >> Mathematics;
        }

        void Display() {
                DisplayBase();
                cout << "Physics: " << Physics << "\n";
                cout << "Chemistry: " << Chemistry << "\n";
                cout << "Mathematics: " << Mathematics << "\n";
        }
};

class Arts : public Student {
public:
        int English, History, Economics;

        void getDataArts() {
                getData();
                entryno = 2;
                cout << "Enter English Marks: ";
                cin >> English;
                cout << "Enter History Marks: ";
                cin >> History;
                cout << "Enter Economics Marks: ";
                cin >> Economics;
        }

        void Display() {
                DisplayBase();
                cout << "English: " << English << "\n";
                cout << "History: " << History << "\n";
                cout << "Economics: " << Economics << "\n";
        }
};

int main() {
        cout<<"******** Enter Science Students *********\n";
        Science sci_stud[k];
        for (int i=0;i<k;i++)
        {
            cout<<"Enter Data Of Student "<<i+1<<":\n";
            sci_stud[i].getDataScience();
            cout<<endl;
        }
        cout<<"******** Enter Arts Students *********\n";

        Arts art_stud[3];
        for (int i=0;i<k;i++)
        {
            cout<<"Enter Data Of Student "<<i+1<<":\n";
            art_stud[i].getDataArts();
            cout<<endl;
        }

        cout<<"*********** Displaying Science Students ***********\n ";
        for (int i=0;i<k;i++)
        {
            cout<<"Entered Data Of Student "<<i+1<<":\n";
            sci_stud[i].Display();
        }
        cout<<"******** Displaying Art Students *********\n";

        for (int i=0;i<k;i++)
        {
        cout<<"Entered Data Of Student "<<i+1<<":\n";
        art_stud[i].Display();

        }

        return 0;
}
