#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

ll p, q, e, d, n, phi, plain, cipher;
string plain_string;
bool text = false;

bool isPrime(ll n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void key_generation()
{
enter:
    cout << "Enter 2 primes p and q: ";
    cin >> p >> q;
    if (!(isPrime(p) && isPrime(q)))
    {
        cout << "Enter valid input!!\n";
        goto enter;
    }
    n = p * q;
    phi = (p - 1) * (q - 1);
enter1:
    cout << "Enter public key e: ";
    cin >> e;
    if (__gcd(e, phi) != 1 || e > phi)
    {
        cout << "Enter valid value of e!!\n";
        goto enter1;
    }
    ll k = 0;
    d = (1 + k * phi) / e;
    while ((1 + k * phi) % e != 0)
    {
        k++;
        d = (1 + k * phi) / e;
    }
    cout << "Public key(n,e): (" << n << "," << e << ")\n";
    cout << "Private key(d): " << d << endl;
}
ll power(ll a, ll b, ll M)
{
    ll res = 1LL;
    while (b)
    {
        if (b % 2)
            res = res * a % M;
        a = a * a % M;
        b /= 2;
    }
    return res;
}
void encryption()
{
    int choice;
    cout << "Press 1 for number and 2 for alphabet string: ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter message as number: ";
        cin >> plain;
        text = false;
    }
    else
    {
        cout << "Enter message as alphabet string(in lowercase): ";
        cin >> plain_string;
        int k = 10;
        plain = 0;
        for (int i = 0; i < plain_string.length(); i++)
        {
            plain = plain * k + int(plain_string[i] - 'a') + 1;
        }
        text = true;
    }
    cout << "Plain text: " << plain << endl;
    cipher = power(plain, e, n);
    cout << "Cipher text: " << cipher << endl;
}

void decryption()
{

    ll plain = power(cipher, d, n);
    if (text)
    {
        string num = to_string(plain);
        plain_string = "";
        for (int i = 0; i < num.length(); i++)
        {
            plain_string += char(int(num[i] - '0') - 1 + 'a');
        }
        cout << "Plain message: " << plain_string << endl;
    }
    else
    {
        cout << "Plain message: " << plain << endl;
    }
}
int main()
{
    int choice;
    while (1)
    {
        cout << "Press 1 for exit and 2 to continue: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Thanks for running";
            break;
        }
        else
            ;
        cout << "*******Key Generation********\n";
        key_generation();
        cout << "*****************************\n\n";
        cout << "*********Encryption**********\n";
        encryption();
        cout << "*****************************\n\n";
        cout << "*********Decryption**********\n";
        decryption();
        cout << "*****************************\n\n";
    }
}
