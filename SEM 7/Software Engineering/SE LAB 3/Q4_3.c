//Declaration Inconsistency
#include "head4.h"
void setName(/*@unused@*/ int f, char *) /*@modifies f->name@*/
{
    printf("Hello");
}
