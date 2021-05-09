
#include <bits/stdc++.h>

using namespace std;

class CellUser {
public:
        float PulseUsed;
};

class PostPaid : public CellUser {
        float fixedFreeTalkTime, rate = 1.90;
public:
        PostPaid(float minutes, float fixed) : CellUser() {
                PulseUsed = minutes;
                fixedFreeTalkTime = fixed;
        }

        void calcBill() {
                float bill;
                if (PulseUsed <= fixedFreeTalkTime) bill = 0;
                else bill = (PulseUsed - fixedFreeTalkTime) * rate;
                cout << "Bill : " << bill << endl;
        }

        float retrive() {
                return (PulseUsed > fixedFreeTalkTime) ? 0 : fixedFreeTalkTime - PulseUsed;
        }
};

class PrePaid : public CellUser {
        float talkTime;

public:
        PrePaid(float minutes, float TalkTime) : CellUser() {
                PulseUsed = minutes;
                talkTime = TalkTime;
        }

        float retrive() {
                return (PulseUsed > talkTime) ? 0 : talkTime - PulseUsed;
        }
};

int main() {
        PostPaid postPaid(100, 60);
        cout << "PostPaid" << endl;
        postPaid.calcBill();
        cout << "TalkTime Remaining: " << postPaid.retrive() << endl << endl;

        PrePaid prePaid(100, 120);
        cout << "PrePaid" << endl;
        prePaid.retrive();
        cout << "TalkTime Remaining: " << prePaid.retrive() << endl;
        return 0;
}
