#include<stdio.h>
void main()
{
    float n,res1,res2;
    int i;
    printf("Enter the number\n");
    scanf("%f",&n);
    printf("The following are the formatting of the floating point numbers\n");
    for(i=1;i<5;i++)
    {
        res1=n/10;
        res2=n*10;
        printf("\t%f*10^(%d)\n",res1,i);
        printf("\t%f*10^(-%d)\n",res2,i);
    }
    printf("The formatting of the number in powers of e is\t");
    printf("%e\n",n);

}
