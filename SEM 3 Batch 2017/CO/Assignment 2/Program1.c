#include<stdio.h>

int main()
{
    char ch;
    short int a;
    float f;
    double d;
    printf("The following are native data types:\n");
    printf("The size of the character is:\t%u\n",sizeof(ch));
    printf("The size of the integer is:\t%u\n",sizeof(a));
    printf("The size of the float is:\t%u\n",sizeof(f));
    printf("Enter the value of character: ");
    scanf("%c",&ch);
    if((ch-'NUL')<=(-128) && (ch-'NUL')<=127)
        printf("The character is within the range\n");
    else
        printf("The character is out of the range\n");
    long int b;
    fflush(stdin);
    printf("Enter the value of integer: ");
    scanf("%ld",&b);
    if(b>=-32768 && b<=32767)
        printf("The number entered is within the range\n");
    else
        printf("The number entered is out of the range\n");
    printf("Enter the value of float: ");
    scanf("%e",&d);
    if(d>=-(108310167974186771.14911748378442) && d<=(108310167974186771.14911748378442))
        printf("The number entered is within the range\n");
    else
        printf("The number entered is out of the range\n");

}
