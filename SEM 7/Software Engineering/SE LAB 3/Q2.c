#include <stdio.h>

void updateEnv(char *str)
{
    char *tmp;
    tmp = getenv("MYENV");
    if (tmp != NULL)
        strcpy(str, tmp);
}

void updateEnvSafe(char *str, size_t strSize) /*@requires maxSet(str @ A3_Q2.c(18,9)) >= strSize @ A3_Q2.c(18,13)@*/
{
    char *tmp;
    tmp = getenv("MYENV");
    if (tmp != NULL)
    {
        strncpy(str, tmp,
                strSize - 1);
        str[strSize - 1] = '/0';
    }
}

int main()
{
    printf("Buffer Owerflow attack\n");
    return 0;
}

// splint A3_Q2.c -preproc +bounds