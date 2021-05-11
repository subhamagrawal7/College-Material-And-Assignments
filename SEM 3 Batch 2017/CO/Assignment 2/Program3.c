#include<stdio.h>
int main()
{
    short int a,b;
    long int c,d;
    printf("FOR SHORT INTEGER NUMBERS\n");
    printf("Enter the first number: ");
    scanf("%hu",&a);
    printf("Enter the second number: ");
    scanf("%hu",&b);
    printf("Addition of the two numbers: %hu\n",(a + b));
    printf("Subtraction of the two numbers: %hu\n",(a>b?a - b:b - a));
    printf("Product of the two numbers: %hu\n",(long long int)((long long int)a*(long long int)b));
    if(b==0)
        printf("Sorry its not divisible as the denominator is zero\n");
    else
    {
        printf("Quotient of the two numbers: %f\n",(float)((float)a/(float)b));
        printf("Remainder of the two numbers: %d\n",(a%b));
    }
    printf("FOR LONG INTEGER NUMBERS\n");
    printf("Enter the first number: ");
    scanf("%ld",&c);
    printf("Enter the second number: ");
    scanf("%ld",&d);
    printf("Addition of the two numbers: %ld\n",(c + d));
    printf("Subtraction of the two numbers: %ld\n",(c>d?c - d:d - c));
    printf("Product of the two numbers: %ld\n",(long long int)((long long int)c*(long long int)d));
    if(d==0)
        printf("Sorry its not divisible as the denominator is zero\n");
    else
    {
        printf("Quotient of the two numbers: %f\n",(double)((double)c/(double)d));
        printf("Remainder of the two numbers: %d\n",(c%d));
    }
}

