#include <stdio.h>

extern int glob1, glob2;
extern int f(void) /*@globals glob1@*/ /*@modifies nothing@*/;
extern void g(void) /*@modifies glob2@*/;
extern void h(void);

void upto(int x)
{
    while (x > f())
        g();
    while (f() < 3)
        h();
}

int main()
{
    printf("Checking for likely infinite loops\n");
    return 0;
}

// splint A3_Q1.1.c -preproc +infloopsuncon