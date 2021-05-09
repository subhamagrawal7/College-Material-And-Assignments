
#include <bits/stdc++.h>

using namespace std;

class ElectricityUser {
public:
        int base;
        float initial, beyond,limit, addon;
        float units;

        float getBill() {
                if (units <= base)
                        return units * initial;

                float cost = base * initial;
                units -= base;
                cost += units * beyond;
                return (cost > limit) ? cost * (1 + addon) : cost;

        }
};

class Domestic : public ElectricityUser {
public:
         Domestic(float noOfUnit) {
                initial = 0.50;
                beyond = 0.60;
                limit = 250.00;
                addon = 0.15;
                units = noOfUnit;
                base=300;
        }
};

class Industrial : public ElectricityUser {
public:
         Industrial(float noOfUnit) {
                initial = 0.25;
                beyond = 0.30;
                limit = 2000.00;
                addon = 0.10;
                units = noOfUnit;
                base=1000;
        }
};

int main() {

        float units;
        cout<<"*******DOMESTIC BILL***********\n";
        cout<<"Enter Domestic Units: ";
        cin>>units;
        Domestic dom(units);
        cout <<"TOTAL BILL = RS. "<< dom.getBill() << "\n";
        cout<<"*******INDUSTRIAL BILL***********\n";
        cout<<"Enter Domestic Units: ";
        cin>>units;
        Industrial ind(units);
        cout << "TOTAL BILL = RS. "<<ind.getBill() << "\n";
        return 0;
}
