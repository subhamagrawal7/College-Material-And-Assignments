#include<stdio.h>
#include<string.h>
#include<math.h>
//Global stack array for conversion
char stck[20];
int top_char=-1;

//Deciding the priority of the operators
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

//push for converting expression
void push_char(char b)
{
    stck[++top_char]=b;
}

//pop for converting expression
char pop_char()
{
    char var;
    var=stck[top_char];
    top_char--;
    return var;
}

//push for evaluating expression
void push(int *p,int n,int *top)
{
    int t=*top;
    t++;
    *(p+t)=n;
    *top=t;
}

//pop for evaluating expression
int pop(int *p,int *top)
{
    int num,t=*top;
    num=*(p+t);
    t--;
    *top=t;
    return(num);
}

void main()
{
    char exp[20],value[20],temp;
    int i=0,j=0,numTemp=0;
    printf("Enter the infix expression(Use dot for multidigit numbers):\t");
    scanf("%s",exp);

    //Converting algorithm
    while(exp[i]!='\0')
    {
        //if the expression is operand
        if(exp[i]>=48 && exp[i]<=57){
            value[j]=exp[i];
            j++;
        }
        //case for a two or three or any digit number.
        else if(exp[i]=='.')
        {
            value[j]=exp[i];
            j++;
        }
        //if its opening paranthasis then directly push
        else if(exp[i]=='('){
            push_char(exp[i]);
        }
        //if closing paranthesis the pop till opening paranthesis
        else if(exp[i]==')'){
            while(stck[top_char]!='('){
                value[j]=pop_char();
                j++;
            }
            temp=pop_char();
        }
        //compare the priorities and pop and push
        else{
            while(priority(stck[top_char]) >= priority(exp[i])){
                value[j]=pop_char();
                j++;
            }
            push_char(exp[i]);
        }
        i++;
    }
    //empty the stack
    while(top_char!= -1){
        value[j]=pop_char();
        j++;
    }
    //set value of last of the string to \0
    value[j]='\0';
    //printf("The post fix expression is: %s\n",value);
    //starting evaluation
    char c[20];
    int stack[20],*p,top=-1;
    int *t=&top;
    int pop1,pop2,num1;
    p=stack;

    //copying the value string to the c string for evaluation
    strcpy(c,value);

    for(i=0;i<strlen(c);i++)
    {
        //if operand then push into the stack
        if(c[i]>=48 && c[i]<=57)
        {
            push(p,c[i]-'0',t);
        }
        else if(c[i]=='.')
        {
            numTemp=pop(p,t);
            i++;
            numTemp=(10*numTemp) + (c[i]-'0');
            push(p,numTemp,t);
        }
        else
        {
            //else pop and evaluate
            pop1=pop(p,t);
            pop2=pop(p,t);
            switch(c[i])
            {
                case '+': pop1=pop2+pop1;
                           break;
                case '-': pop1=(pop2-pop1);
                           break;
                case '*': pop1=pop2*pop1;
                           break;
                case '/': pop1=pop2/pop1;
                           break;
                case '^': pop1=pow(pop2,pop1);
                           break;
                default: break;
            }
            //again push the evaluated expression
            push(p,pop1,t);
        }
    }
    //empty the stack and give answer
    i=pop(p,t);
    printf("The value is of the expression is : %d",i);

}
