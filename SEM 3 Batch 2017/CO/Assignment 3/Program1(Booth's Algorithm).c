#include<stdio.h>
void main()
{
    int i,j=0,k,l,a[4],m[4],q[4],n[4]={0,0,0,0},*p,carry=0;
    int num[4]={0,0,0,1};
    char c[5],s[5];
    p=&carry;
    printf("Enter the multiplicand\n");
    scanf("%s",c);
    printf("Enter the multiplier\n");
    scanf("%s",s);
    for(i=0;i<4;i++)
    {
        m[i]=c[i]-'0';
        q[i]=s[i]-'0';
        if(m[i]==1)
            n[i]=0;
        else
            n[i]=1;
    }
    for(i=3;i>=0;i--)
        n[i]=add(n[i],num[i],p);
    *p=0;
    if(q[0]==0)
    {
        for(i=0;i<4;i++)
            a[i]=0;
    }
    else
    {
        for(i=0;i<4;i++)
            a[i]=1;
    }
    for(k=0;k<4;k++)
    {
        *p=0;
        if(q[3]==1 && j==0)
        {
            for(i=3;i>=0;i--)
                a[i]=add(a[i],n[i],p);
            j=q[3];
            l=a[3];
            for(i=3;i>0;i--)
            {
                a[i]=a[i-1];
                q[i]=q[i-1];
            }
            q[0]=l;
        }
        else if(q[3]==0 && j==1)
        {
            for(i=3;i>=0;i--)
                a[i]=add(a[i],m[i],p);
            j=q[3];
            l=a[3];
            for(i=3;i>0;i--)
            {
                a[i]=a[i-1];
                q[i]=q[i-1];
            }
            q[0]=l;
        }
        else
        {
            j=q[3];
            l=a[3];
            for(i=3;i>0;i--)
            {
                a[i]=a[i-1];
                q[i]=q[i-1];
            }
            q[0]=l;
        }
    }
    printf("The answer is :\t");
    for(i=0;i<4;i++)
        printf("%d",a[i]);
    for(i=0;i<4;i++)
        printf("%d",q[i]);
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
