#include<bits/stdc++.h>
using namespace std;

void Find_First(char[], char);
void Array_Manipulation(char[], char);
 
int nop;
char production[25][25];
 
int main()
{
      char option,ch,array[25]; 
      int i;
      cout<<"NOTE: Enter only one production in one and use equal to instead of arrow and dollar symbol instead of epsilon";
      cout<<"\nSample production: S=abc";
      cout<<endl;
      cout<<endl;
      cout<<"Enter Total Number of Productions: ";
      cin>>nop;
      for(i = 0; i < nop; i++)
      {
            cout<<"\nValue of Production "<<i+1<<" : ";
            cin>>production[i];
      }
      do
      {
            cout<<"\nEnter a Value to Find First: ";
            cin>>ch;
            Find_First(array, ch);
            cout<< "\nFirst Value of "<<ch<<"{ ";
            for(i = 0; array[i] != '\0'; i++)
            {        
                  cout<<array[i]<<" ";
            }
            cout<<"}\n";
            cout<<"To continue , Input Y else Input N: ";
            cin>>option;
      }while(option == 'Y');
      return 0;
}
 
void Find_First(char* array, char ch)
{
      int i, j, k;
      char temp[20];
      int x;
      temp[0] = '\0';
      array[0] = '\0';
      if(!(isupper(ch)))
      {
            rem_dup(array, ch);
            return ;
      }
      for(i = 0; i < nop; i++)
      {
            if(production[i][0] == ch)
            {
                  if(production[i][2] == '$') 
                  {
                        rem_dup(array, '$');
                  }
                  else
                  {
                        j = 2;
                        while(production[i][j] != '\0')
                        {
                              x = 0;
                              Find_First(temp, production[i][j]);
                              for(k = 0; temp[k] != '\0'; k++)
                              {
                                    rem_dup(array,temp[k]);
                              }
                              for(k = 0; temp[k] != '\0'; k++)
                              {
                                    if(temp[k] == '$')
                                    {
                                          x = 1;
                                          break;
                                    }
                              }
                              if(!x)
                              {
                                    break;
                              }
                              j++;
                        }
                  }     
            }
      }
      return;
}
 
void rem_dup(char array[], char value)
{
      int temp;
      for(temp = 0; array[temp] != '\0'; temp++)
      {
            if(array[temp] == value)
            {
                  return;
            }
      }
      array[temp] = value;
      array[temp + 1] = '\0';
}
