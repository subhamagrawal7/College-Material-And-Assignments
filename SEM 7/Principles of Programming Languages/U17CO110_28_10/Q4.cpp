
#include <bits/stdc++.h>

using namespace std;

class Patient {
        string Name, Disease;
public:
        Patient(string name, string disease) {
                Name = name;
                Disease = disease;
        }

        void PutData() {
                cout << "Name: " << Name << "\n";
                cout << "Disease: " << Disease << "\n";
        }
};

class In_Patient : public Patient {
        float RoomRent;
public:
        In_Patient(string name, string disease, float roomRent) : Patient((name),(disease)) {
                RoomRent = roomRent;
        }

        void PutDataInPatient() {
                cout<<"*****************************************\n";
                cout << "IN PATIENT \n";
                PutData();
                cout << "RoomRent: " << RoomRent << endl;
                cout<<"*****************************************\n";
        }
};

class Out_Patient : public Patient {
        float OPD_Charges;
public:
        Out_Patient(string name, string disease, float roomRent) : Patient((name), (disease)) {
                OPD_Charges = roomRent;
        }

        void PutDataOutPatient() {
                cout<<"*****************************************\n";
                cout << "OUT PATIENT \n";
                PutData();
                cout << "OPD_Charges: " << OPD_Charges << endl;
                cout<<"*****************************************\n";
        }
};

int main() {

        In_Patient p1("Rohan", "Dengue", 30000);
        p1.PutDataInPatient();
        Out_Patient p2("Rajni", "Throat Infection", 50);
        p2.PutDataOutPatient();
        return 0;
}
