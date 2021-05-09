#include <bits/stdc++.h>

using namespace std;

class MathUtility
{
public:
    static int64_t fact(int n)
    {
        int64_t res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }

    static bool isEven(int n) { return n % 2 == 0; }

    static bool isOdd(int n) { return n % 2 == 1; }

    static int64_t gcd(int64_t a, int64_t b) { return __gcd(a, b); }
};

class checkMethods
{
public:
    static void doIt()
    {
        cout << "fact(5) : " << MathUtility::fact(5) << "\n";

        cout << "isOdd(5): " << MathUtility::isOdd(5) << ", isOd(4): " << MathUtility::isOdd(4) << "\n";

        cout << "isEven(5): " << MathUtility::isEven(5) << ", isEven(4): " << MathUtility::isEven(4) << "\n";

        cout << "gcd(25, 120): " << MathUtility::gcd(25, 120) << "\n";
    };
};

int main()
{
    cout << fixed << setprecision(2);
    checkMethods::doIt();
    return 0;
}