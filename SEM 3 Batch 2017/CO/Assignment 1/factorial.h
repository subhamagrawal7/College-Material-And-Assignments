#ifndef factorial_h
#define factorial_h

#include<stdio.h>
int fact(int n)
{
    if(n>0)
        return(n*fact(n-1));
    else
        return(1);
}
#endif // factorial_h
