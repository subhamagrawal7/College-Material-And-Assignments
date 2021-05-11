#include<stdio.h>
#include "binary.h"
#include "decimal.h"
#include "factorial.h"
int main()
{
    int n;
    int num;

    printf("1.Decimal to Binary\n");
    printf("2.Binary to Decimal\n");
    printf("3.Factorial\n");
    printf("4.Exit\n");
    while(1)
    {
        printf("\nEnter the choice number\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : decimal();
                     break;
            case 2 : binary();
                     break;
            case 3 :
                     printf("Enter the number\n");
                     scanf("%d",&num);
                     printf("factorial is %d",fact(num));
                     break;
            case 4 : exit(0);
            default : printf("the number entered is wrong\n");
                      break;
        }
    }
}
