#include <bits/stdc++.h>
using namespace std;
#define vsize 5

class Vector {
private:
        int el[vsize]{};
public:
        Vector() = default;

        void read() {
                // reading from member function
                cout << "Enter 5 Elements" << endl;
                for (int &i : el) cin >> i;
        }

        Vector(const Vector &s) {
                // copy constructor
                for (int i = 0; i < vsize; i++) el[i] = s.el[i];
        }

        Vector operator+(Vector &source) {
                // overloaded + operator
                Vector final{};
                for (int i = 0; i < vsize; i++) final.el[i] = source.el[i] + el[i];
                return final;
        }

        friend ostream &operator<<(ostream &os, const Vector &obj) {
                // overloaded stream insertion
                os << "Vector{ ";
                for (int i: obj.el) os << i << " ";
                os << "}\n";
                return os;
        }

        friend int operator>>(istream &is, Vector &obj) {
                // overloaded stream extraction
                cout << "Enter 5 Elements" << endl;
                for (int &i: obj.el) is >> i;
        }

};

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        Vector x;
        x.read();
        cout << x << endl;

        Vector y{x};

        Vector z = x + y;
        cout << z << endl;

        Vector a;
        cin >> a;
        cout << a;
        return 0;
}