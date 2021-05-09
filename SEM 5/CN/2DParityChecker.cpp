#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the no of bits of data: ";
    cin>>n;
    int mat[n+1][n+1];
    cout<<"Enter the matrix: ";
    cout<<endl;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i<n && j<n)
                cin>>mat[i][j];
            else
                mat[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][n] = (mat[i][j]+mat[i][n])%2;
            mat[n][j] = (mat[i][j]+mat[n][j])%2;
        }
    }
    for(int i=0;i<n;i++)
    {
        mat[n][n]=(mat[n][n]+mat[n][i])%2;
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}