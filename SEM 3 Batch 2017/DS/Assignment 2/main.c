#include<stdio.h>
#include<string.h>
#include "program.h"

void main()
{
    char s[50]={'\0'},c[50]={'\0'},m[50],cs[50],ch;
    int l,i,j;
    //Program 1
    printf("Enter the first string:\t");
    gets(c);
    //scanf("%[^\n]s",c);
    l=length(c);
    printf("The length is : %d\n",l);
    //Program 2
    printf("Enter the second string:\t");
    gets(s);
    //scanf("%[^\n]s",s);
    printf("The concatenation of the two strings is :\t");
    concate(c,s);
    //Program 3
    fflush(stdin);
    printf("\nEnter the character to be searched in the first string:\t");
    scanf("%c",&ch);
    first(c,ch);
    //Program 4
    fflush(stdin);
    printf("Enter the character to be searched in the first string:\t");
    scanf("%c",&ch);
    last(c,ch);
    //Program 5
    printf("The concatenation of the first main string and its reversal is: \t");
    revConcate(c,s);
    //Program 6
    printf("\nThe concatenation of the main string and its duplicate is:\t");
    duplicate(c);
    //Program 7
    printf("RESULT OF COMPARISION OF THE TWO STRINGS:\t");
    comp(c,s);
    //Program 8
    printf("\nRESULT OF COMPARISION OF THE TWO STRINGS WITHOUT CASE SENSITIVITY:\t");
    compWithoutCase(c,s);
    //Program 9
    for(i=0;i<=l;i++)
    {
        cs[i]=c[i];
    }
    printf("The reverse of the main string is:\t");
    rev(c);
    //Program 10
    printf("The main string in upper case is: \t");
    upperCase(cs);
    //Program 11
    printf("The main string in lower case is: \t");
    lowerCase(cs);
    //Program 12
    fflush(stdin);
    printf("The main string in Title case is :\t");
    titleCase(cs);
    //Program 13
    printf("Enter the sub string to be inserted between the main string:\t");
    gets(m);
    printf("\n");
    printf("Enter the position to be inserted:\t");
    scanf("%d",&j);
    for(i=0;i<=l;i++)
    {
        cs[i]=c[i];
    }
    replace(cs,m,j);
    //Program 14
    printf("Enter the sub string which you want to search in the main string:\t");
    fflush(stdin);
    gets(m);
    indexSUBinMAIN(c,m);
    //Program 15
    palindrome(c);
    //Program 16
    vowels(c);
    //Program 17
    characterWords(c);
}

