#include<stdio.h>
#ifndef program_h
#define program_h

//declarations
int length(char*);
void concate(char* c,char* s);
void first(char* p,char ch);
void last(char* p,char ch);
void revConcate(char* p,char* q);
void duplicate(char* s);
void comp(char* p,char* q);
void compWithoutCase(char* p,char* q);
void rev(char* p);
void lowerCase(char* p);
void upperCase(char* p);
void titleCase(char* p);
void replace(char* p,char* q,int a);
void indexSUBinMAIN(char* p,char* q);
void palindrome(char* p);
void vowels(char* p);
void characterWords(char* p);

int length(char* p)
{
    int i;
    for(i=0;*(p+i)!='\0';i++);
    return(i);
}
void concate(char* c,char* s)
{
    int l,i,j,m;
    char res[100];
    l=length(c);
    m=length(s);
    for(i=0;i<l;i++)
    {
        res[i]=c[i];
    }
    i=0;
    for(j=l;j<(l+m);j++ && i++)
    {
        res[j]=s[i];
    }
    res[l+m]='\0';

    for(i=0;i<(l+m);i++)
    {
        printf("%c",res[i]);
    }
    printf("\n");
}
void first(char* p,char ch)
{
  int i;
  for(i=0;*(p+i)!='\0';i++)
  {
    if(*(p+i)==ch)
    {
            printf("First occurrence of the symbol is at index = %d\n",(i+1));
            break;
    }
  }
  if(*(p+i)=='\0')
       {
            printf("Sorry the symbol is not present in the string.\n");
       }
}

void last(char* p,char ch)
{
  int i,l,n=0;
  l=length(p);
  for(i=l-1;i>=0;i--)
  {
      if((p[i]-'0')==(ch-'0'))
      {
          n=1;
          //printf("%d",i);
          break;
      }
  }
  if(n==1)
  {
      printf("The last occurrence of the character is %d\n",i+1);
  }
  else
  {
      printf("Sorry the character is not present in the main string\n");
  }

}
void revConcate(char* p,char* q)
{
    int i,j,l;
    char rev[30];
    l=length(q);
    j=0;
    for(i=l-1;i>=0;i--)
    {
        rev[j]=q[i];
        j++;
    }
    rev[l]='\0';
    concate(p,rev);
}
void duplicate(char* s)
{
        concate(s,s);
}
void comp(char* p,char* q)
{
    int i,n=0,l,m;
    l=length(p);
    m=length(q);
    if(l==m)
    {
        for(i=0;i<l;i++)
        {
            if((p[i]-'0')==(q[i]-'0'))
               n++;
        }
        if(n==l)
            printf("The two strings are same\n");
        else
            printf("The two strings are not same\n");
    }
    else
        printf("The two strings are not same\n");
}
void compWithoutCase(char* p,char* q)
{
    int i,n=0,l,m;
    l=length(p);
    m=length(q);
    if(l==m)
    {
        for(i=0;i<l;i++)
        {
            if((p[i]-q[i])==0 || (p[i]-q[i]==32))
               n++;
        }
        if(n==l)
            printf("The two strings are same.\n");
        else
            printf("The two strings are not same.\n");
    }
    else
        printf("The two strings are not same.\n");
}
void rev(char* p)
{
    int i,j,l;
    char rev[30];
    l=length(p);
    j=0;
    for(i=l-1;i>=0;i--)
    {
        rev[j]=p[i];
        j++;
    }
    rev[l]='\0';
    printf("%s",rev);
    printf("\n");
}
void upperCase(char* p)
{
    int i,l;
    l=length(p);
    for(i=0;i<l;i++)
    {
        if(p[i]>=97 && p[i]<=122)
        {
            p[i]=p[i]-32;
        }
    }
    printf("%s",p);
    printf("\n");
}
void lowerCase(char* p)
{
    int i,l;
    l=length(p);
    for(i=0;i<l;i++)
    {
        if(p[i]>=65 && p[i]<=90)
        {
            p[i]=p[i]+32;
        }
    }
    printf("%s",p);
    printf("\n");
}
void titleCase(char* p)
{
    int i,l;
    l=length(p);
    if(p[0]>=97 && p[0]<=122)
    {
        p[0]=p[0]-32;
    }
    for(i=0;i<l;i++)
    {
        if(p[i]==32)
        {
            if(p[i+1]>=97 && p[i+1]<=122)
            {
                p[i+1]=p[i+1]-32;
            }
        }
    }
    printf("%s",p);
    printf("\n");
}
void replace(char* p,char* q,int a)
{
    int l,m,i,j;
    l=length(p);
    m=length(q);
    if(a>l)
    {
        printf("The position is not valid\n");
        goto pa;
    }
    else
    {
        j=0;
        for(i=a-1;i<m+(a-1);i++ && j++)
        {
            p[i]=q[j];
        }
    }
    p[i+1]='\0';
    l=i;
    for(i=0;i<=l-1;i++)
        printf("%c",p[i]);
    printf("\n");
    pa:;
    printf("\n");
}
void indexSUBinMAIN(char* p,char* q)
{
    int i,l,m,j,c=0,cou=0;
    l=length(q);
    m=length(p);
    for(i=0;i<m;i++)
    {
        if(p[i]==q[0])
        {
            for(j=0;j<l;j++)
            {
                if(p[i+j]==q[j])
                    cou++;
            }
            if(cou==l)
                printf("\tThe sub string is present at %d index.\n",i+1);
                c++;
        }
        cou=0;
    }
    if(c==0)
        printf("Sorry no substring present\n");
}
void palindrome(char* p)
{
    int i,l,m=0;
    l=length(p);
    for(i=0;i<(l/2);i++)
    {
        if(p[i]==p[l-i-1])
                m++;
    }
    if(m==(int)(l/2))
        printf("The string is a palindrome\n");
    else
        printf("The main string is not a palindrome\n");
}
void vowels(char* p)
{
    int i,l,n=0,a[10]={0,0,0,0,0,0,0,0,0,0};
    char c[11]={"aeiouAEIOU"};
    l=length(p);

    for(i=0;i<l;i++)
    {
        if(p[i]=='a')
            a[0]=a[0]+1;
        if(p[i]=='e')
            a[1]=a[1]+1;
        if(p[i]=='i')
            a[2]=a[2]+1;
        if(p[i]=='o')
            a[3]=a[3]+1;
        if(p[i]=='u')
            a[4]=a[4]+1;
        if(p[i]=='A')
            a[5]=a[5]+1;
        if(p[i]=='E')
            a[6]=a[6]+1;
        if(p[i]=='I')
            a[7]=a[7]+1;
        if(p[i]=='O')
            a[8]=a[8]+1;
        if(p[i]=='U')
            a[9]=a[9]+1;
    }
    for(i=0;i<10;i++)
    {
        if(a[i]!=0)
            printf("The vowel %c is present %d times\n",c[i],a[i]);
    }
}
void characterWords(char* p)
{
    int c,i,l=1;
    c=length(p);
    printf("The total number of characters is %d\n",c);
    for(i=0;i<c;i++)
    {
        if(p[i]==32)
        {
            if((p[i+1]>=65 && p[i+1]<=90) || (p[i+1]>=97 && p[i+1]<=122))
                l++;
        }
    }
    printf("The total number of words is %d\n",l);
}
#endif // program_h

