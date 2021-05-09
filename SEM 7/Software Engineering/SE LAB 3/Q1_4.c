#include <stdio.h>

int main()
{
    int x = 1;
    if (x > 3)
        ;
    if (x > 3)
        x++;

    printf("Checking Empty statement after an if , while or for\n");
    return 0;
}

// splint A3_Q1.4.c -preproc