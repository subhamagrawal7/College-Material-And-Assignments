#ifndef decimal_h
#define decimal_h

#include<stdio.h>
void decimal()
{
    int n,m,i=0,*p,rem,j;
    printf("Enter a decimal number\n");
    scanf("%d",&n);
    m=n;
    while(m!=0)
    {
        i++;
        m=m/2;
    }
    p=(int)calloc(i,sizeof(int));
    for(j=0;j<i;j++)
    {
        rem=n%2;
        //printf("%d\n",rem);
        *(p+j)=rem;
        n=n/2;
    }
    reverse(p,i);
    printf("The binary number is\n");
    for(j=0;j<i;j++)
    {
        printf("%d",p[j]);
    }

}
void reverse(int* p,int n)
{
    int i,temp;
    for(i=0;i<(n/2);i++)
    {
       temp=*(p+i);
       *(p+i)=*(p+(n-i-1));
       *(p+(n-i-1))=temp;
    }
}
#endif // decimal_h
