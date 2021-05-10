#include<stdio.h>
#include<string.h>
char stck[20];
int top=-1;

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
}

void push(char b)
{
    stck[++top]=b;
}

char pop()
{
    char var;
    var=stck[top];
    top--;
    return var;
}

void main()
{
    char exp[20],value[20],temp;
    int i=0,j=0;
    printf("Enter the infix expression\n");
    scanf("%s",exp);
    while(exp[i]!='\0')
    {
        if(exp[i]>=48 && exp[i]<=57){
            value[j]=exp[i];
            j++;
        }
        else if(exp[i]=='.')
        {
            value[j]=exp[i];
            j++;
        }
        else if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(stck[top]!='('){
                value[j]=pop();
                j++;
            }
            temp=pop();
        }
        else{
            while(priority(stck[top]) >= priority(exp[i])){
                value[j]=pop();
                j++;
            }
            push(exp[i]);
        }
        i++;
    }
    while(top!= -1){
        value[j]=pop();
        j++;
    }
    value[j]='\0';
    printf("%s",value);

}
