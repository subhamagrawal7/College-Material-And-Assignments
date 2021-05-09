#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    int BOOKNO;
    string BOOKTITLE;
    float PRICE;
    float TOTALCOST(int n)
    {
        return PRICE * n;
    }

public:
    void INPUT()
    {
        cout << "Enter BOOK NO.: ";
        cin >> BOOKNO;
        cout << "Enter BOOK TITLE: ";
        cin.ignore();
        getline(cin, BOOKTITLE);
        while (BOOKTITLE.length() > 20)
        {
            cout << "max 20 chars.\n";
            cout << "Enter Book title: " << endl;
            cin.ignore();
            getline(cin, BOOKTITLE);
        }
        cout << "Enter PRICE per copy: ";
        cin >> PRICE;
    }
    void PURCHASE()
    {
        int n;
        cout << "Enter the no. of copies to be purchased: ";
        cin >> n;
        cout << "Total cost to be paid: " << TOTALCOST(n);
    }
};
int main()
{
    Book b;
    b.INPUT();
    b.PURCHASE();
}