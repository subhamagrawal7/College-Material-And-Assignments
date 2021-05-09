#include <iostream>
using namespace std;

class Bank {
private:
    long accNo;
    string name;
    string type;
    long balance;

public:
    void OpenAccount()
    {
        cout << " Enter Account Number: ";
        cin >> accNo;
        cin.ignore();
        cout << " Enter Name: ";
        getline(cin, name);
        while (name.length() > 20) {
        cout<<"Max characters 20!!\n";
        cout << "Enter Name(max 20 chars): ";
        getline(cin, name);
        }
        cout<<" Enter account Type:";
        cin>>type;
        cout << " Enter  Balance: ";
        cin >> balance;
    }
    void ShowAccount()
    {
        cout << " Account Number: " << accNo << endl;
        cout << " Name: " << name << endl;
        cout<<" Account Type: "<<type<<endl;
        cout << " Balance: " << balance << endl;
    }

    void Show_balance()
    {

        cout << " Name: " << name << endl;
        cout << " Balance: " << balance << endl;
    }

    void Deposit()
    {
        long amt;
        cout << "Enter Amount you want to deposit: ";
        cin >> amt;
        balance = balance + amt;
        cout<<"\n So Amount Deposited Successfully!! Updated Balance : "<<balance;
    }
    void Withdrawal()
    {
        long amt;
        cout << "Enter Amount you want to withdraw: ";
        cin >> amt;
        if (amt <= balance)
            {
                balance = balance - amt;
                cout<<"\n So Amount Withdrawn Successfully!! Updated Balance : "<<balance;

            }
        else
            cout << "Less Balance...Cannot Withdraw!" << endl;
    }
};


int main()
{
    Bank client[5];

    int found = 0, a, ch, i;
    for (i = 0; i <= 4; i++) {
        cout<<"Enter Account Details of Customer "<<i+1<<endl;
        client[i].OpenAccount();
        cout<<"\n -----------------------------\n";
    }

    while(1)
    {
        cout<<"\n********************************************************************************************\n";
        cout<<"Press 1.) Display complete information, 2.) Display balance , 3.) Deposit Amount, 4.) Withdraw Amount 5.) Exit" << endl;

        cout << "\n Please input your choice: ";
        cin >> ch;
        cout<<"********************************************************************************************";

        switch (ch) {
        case 1:
            cout << "\n Enter customer number to display info: ";
            cin >> a;
            if(a<1||a>5)
            cout<<"No customer present in data!!";
            else
            client[a-1].ShowAccount();

            break;
        case 2:
            cout << "\n Enter customer number to display balance: ";
            cin >> a;
            if(a<1||a>5)
            cout<<"No customer present in data!!";
            else
            client[a-1].Show_balance();
            break;
        case 3:
            cout << "\n Enter customer number to deposit : ";
            cin >> a;
            if(a<1||a>5)
            cout<<"No customer present in data!!";
            else
            client[a-1].Deposit();
            break;

        case 4:
            cout << "\n Enter customer number to withdraw money : ";
            cin >> a;
            if(a<1||a>5)
            cout<<"No customer present in data!!";
            else
            client[a-1].Withdrawal();
            break;
        case 5:
            cout << "Have a nice day" << endl;
            goto last;
		default:
            cout << "Wrong Option!!! Enter Again" << endl;
        }
    }
    last:
    return 0;
}





















