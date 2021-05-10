#include<stdio.h>
#include<string.h>
void main()
{
    int m[8]={0,0,0,0,0,0,0,0};
    int sum[8]={0,0,0,0,0,0,0,0};
    int i,j,carry=0,k,*p,l;
    p=&carry;
    char c[4],s[4];
    printf("Enter the multiplicand\n");
    fflush(stdin);
    gets(c);
    printf("Enter the multiplier\n");
    fflush(stdin);
    gets(s);
    k=7;
    for(j=7;j>=4;j--)
    {
        for(i=0;i<8;i++)
            m[i]=0;
        if(s[k-4]=='0')
            k--;
        else
        {
            for(i=k,l=3;i>=k-3 && l>=0;i--,l--)
            m[i]=c[l]-'0';
            /*for(i=0;i<7;i++)
                printf("%d",m[i]);
                printf("\n");*/

            for(i=7;i>=0;i--)
            {
                sum[i]=add(sum[i],m[i],p);
            }
            /*for(i=0;i<7;i++)
                printf("%d",sum[i]);
            printf("\n");*/

            k--;
        }
    }
    printf("The unsigned multiplication of the two numbers is:\t");
    for(i=0;i<8;i++)
    {
        printf("%d",sum[i]);
    }


}
int add(int a,int b,int* p)
{
    if(a==1 && b==1)
    {
        if(*p==1)
        {
            return(1);
        }
        else
        {
            *p=1;
            return(0);
        }
    }
    if(a==0 && b==0)
    {
        if(*p==1)
        {
                *p=0;
                return(1);
        }
        else
            return(0);
    }
    else
    {
        if(*p==1)
        {
                return(0);
        }
        else
            return(1);
    }
}

