#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

class Fraction {
    private:
    int num;
    int den;

    public:
    Fraction(int top, int bottom) {
        num = top;
        den = bottom;
    }

    Fraction(int top) {
        num = top;
        den = 1;
    }

     Fraction(const Fraction &f)
    {
    	num = f.num;
    	den = f.den;
	}

	void evfract()
	{
		double z = (double)((double)num/(double)den);

		cout<<"\n The evaluated fraction is : "<<z<<endl;
	}

	void invert()
	{
		double y = (double)((double)num/(double)den);
		double i = (double) (1/y);

		cout<<"\n The inverse of the given rational number is: "<<i<<endl;

	}

};

int main()
{
	int num,den;
	cout<<"\n Enter the numerator : ";
	cin>>num;
	cout<<"\n Enter the denominator : ";
	cin>>den;

    cout<<"\nParameterised constructors with two arguments\n";
    Fraction frac(num,den);

    frac.evfract();
    frac.invert();

    cout<<"\nParameterised constructors with one argument\n";
    Fraction frac1(num);

    frac1.evfract();
    frac1.invert();

    cout<<"\nCopy constructor\n";
    Fraction frac2(num,den);
    Fraction frac3 = frac2;
    frac3.evfract();
    frac3.invert();

 return 0;
}
