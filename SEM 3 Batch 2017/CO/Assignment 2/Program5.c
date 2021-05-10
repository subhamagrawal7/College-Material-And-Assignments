#include<stdio.h>
void main()
{
    char c[5],s[5];
    int sum[4],i,carry=0,*p,comp[4],sub[4];
    int z[4]={0,0,0,1};
    p=&carry;
    printf("Enter the binary numbers\n");
    fflush(stdin);
    scanf("%s",c);
    scanf("%s",s);
    for(i=3;i>=0;i--)
    {
        sum[i]=add(c[i]-'0',s[i]-'0',p);
    }
    if(c[0]-'0' == s[0]-'0')
    {
        if(sum[0] == c[0]-'0')
        {
            printf("The sum is ");
            for(i=0;i<=3;i++)
                printf("%d",sum[i]);
        }
        else
            printf("\nThere is overflow in addition\n");
    }
    else
    {
        printf("\nThe sum is ");
            for(i=0;i<=3;i++)
                printf("%d",sum[i]);
    }
    *p=0;
    for(i=3;i>=0;i--)
    {
        comp[i]=s[i]-'0';
        if(comp[i]==1)
            comp[i]=0;
        else
            comp[i]=1;
    }
    for(i=3;i>=0;i--)
    {
        comp[i]=add(comp[i],z[i],p);
    }
    *p=0;
    for(i=3;i>=0;i--)
    {
        sub[i]=add(c[i]-'0',comp[i],p);
    }
    if(c[0]-'0' == comp[0])
    {
        if(sub[0] == c[0]-'0')
        {
            printf("\nThe sub is ");
            for(i=0;i<=3;i++)
                printf("%d",sub[i]);
        }
        else
            printf("\nThere is overflow in subtraction due to addition of 2's compliment\n");
    }
    else
    {
        printf("\nThe sub is ");
            for(i=0;i<=3;i++)
                printf("%d",sub[i]);
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
