#ifndef binary_h
#define binary_h

#include<stdio.h>
#include<string.h>
void binary()
{
    char s[20];
    int i,l,count=0,j,decimal=0;
    printf("Enter the binary number\n");
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]=='0' || s[i]=='1')
            count++;
    }
    if(count<l)
    {
        printf("The number is not binary\n");
        return;
    }
    for(i=l-1;i>=0;i--)
    {
        j=s[i] - '0';
        //printf("%d\n",j);
        decimal=decimal + (j*(power(l-i-1)));
    }
    printf("The decimal number is %d",decimal);

}
int power(int n)
{
    int i,j=1;
    if(n<1)
        return(1);
    else
    {
        for(i=1;i<=n;i++)
        {
          j=(j*2);
        }
        return(j);
    }
}
#endif // binary_h
