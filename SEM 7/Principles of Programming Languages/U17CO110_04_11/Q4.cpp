#include <bits/stdc++.h>

using namespace std;

class Bag
{
    int arr[50];
    int size;

public:
    Bag(int s)
    {
        size = s;
        for (int i = 0; i < size; i++)
        {
            arr[i] = i % 10 + 1;
        }
    }

    int &operator[](int index)
    {
        if (index >= size)
        {
            cout << "\nOut of bound!";
            exit(0);
        }
        return arr[index];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
};

int main()
{
    Bag arr1(10);
    arr1[2] = 6;
    arr1.print();
    arr1[8] = 6;
    return 0;
}