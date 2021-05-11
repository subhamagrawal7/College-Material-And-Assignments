#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("Addition of the two numbers: %d\n",(a + b));
    printf("Subtraction of the two numbers: %d\n",(a>b?a - b:b - a));
    printf("Product of the two numbers: %d\n",(a*b));
    if(b==0)
        printf("Sorry its not divisible as the denominator is zero\n");
    else
    {
        printf("Quotient of the two numbers: %f\n",(float)((float)a/(float)b));
        printf("Remainder of the two numbers: %d\n",(a%b));
    }
}
