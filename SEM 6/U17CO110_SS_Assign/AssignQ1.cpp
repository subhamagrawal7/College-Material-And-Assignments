#include<bits/stdc++.h>
using namespace std;

int main()
{
    int state,inputSymbol;
    
    cout<<"Enter number of states in DFA : ";
    cin>>state;
    cout<<"Enter nunber of input symbols DFA : ";
    cin>>inputSymbol;
    cout<<"Complete the production table : \n";
    cout<<"   ";
    for(int i=0;i<inputSymbol;i++)
        cout<<i<<" ";
        
    cout<<"\n";
    char productionRule[state][inputSymbol]={};
    for(int i=0;i<state;i++)
    {
        cout<<" "<<char(i+65)<<" ";
        for(int j=0;j<inputSymbol;j++)
        {
            cin>>productionRule[i][j];
        }
    }
    
    char currentState,initialState;
    cout<<"Enter initial state : ";
    cin>>initialState;
    
    int targets;
    cout<<"Enter total number of final states : ";
    cin>>targets;
    
    set <char> finalStates;
    cout<<"Enter final stattes : ";
    for(int i=0;i<targets;i++)
    {
        char temp;
        cin>>temp;
        finalStates.insert(temp);
    }
    
    string str;
    takeString:
    cout<<"Enter string (ending with $) : ";  
    cin>>str;
    currentState = initialState;
    for(auto itr = str.begin(); itr!= str.end() ; itr++)
    {   
        if(*itr == '$')
            break;
            
        int temp = (int) currentState;
        currentState = productionRule[temp-65][*itr-48];
    }
    
    if(finalStates.find(currentState) == finalStates.end())
        cout<<str<<" is invalid.\n\n";
    else
        cout<<str<<" is valid.\n\n";
        
    int choice;
    takeChoice:
    cout<<"**********Menu************\n";
    cout<<"         1. Continue\n";
    cout<<"         0. Exit\n";
    cin>>choice;
    switch(choice)
    {
        case 0:
            return 0;
        case 1 : 
        cout<<"\n";
            goto takeString;
            break;
        default :
            cout<<"Invalid Choice !!!\n\n";
            goto takeChoice;
            break;
    }
    return 0;
}




