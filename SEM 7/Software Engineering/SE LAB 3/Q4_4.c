//Require and Ensure Clauses
#include <stdio.h>
#include <string.h>
void /*@alt char * @*/ strcpy(/*@unique@*/ /*@out@*/ /*@returned@*/ char *s1, char *s2)
    /*@modifies *s1@*/
    /*@requires maxSet(s1) >=3 @*/
    /*@ensures maxRead(s1) >= maxRead (s2) @*/;
void updateEnv(char *str1)
{
    char *tmp;
    tmp = "MYENV";

    str1 = "i";
    if (tmp != NULL)
        strcpy(str1, tmp);
}
