#include <bits/stdc++.h>
using namespace std;

class String {
private:
        char *str;
        int len;
public:
        String() {
                // default constructor
                str = new char[1];
                *str = '\0';
                len = strlen(str);
        };

        String(const String &source) {
                // copy constructor
                str = new char[strlen(source.str) + 1];
                strcpy(str, source.str);
                len = strlen(str);
        }

        explicit String(const char *s) {
                // overloaded constructor
                if (s == nullptr) {
                        str = new char[1];
                        *str = '\0';
                } else {
                        str = new char[strlen(s) + 1];
                        strcpy(str, s);
                }
                len = strlen(str);
        }

        void display() {
                // display
                cout << str << endl;
                cout << "len: " << len << "\n";
        }

        String operator+(String &source) {
                // +operator overloaded.
                String final;
                strcat(str, source.str);
                strcpy(final.str, str);
                final.len = strlen(final.str);
                return final;
        }
};

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        String a{"AAA"};
        String b{"BBB"};
        String c = a + b;
        c.display();
        return 0;
}