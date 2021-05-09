#include <stdio.h>

typedef enum { YES, NO, DEFINITELY, PROBABLY, MAYBE } ynm;

void decide(ynm y)
{
    switch (y)
    {
    case PROBABLY:
        break;
    case NO:
        printf("No!");
        break;
    case MAYBE:
        printf("Maybe");
        break;
    /*@fallthrough@*/
    case YES:
        printf("Yes!");
        break;
    }
}

int main()
{
    printf("Checking fall through missing switch cases");
    return 0;
}

// splint A3_Q1.3.c -preproc