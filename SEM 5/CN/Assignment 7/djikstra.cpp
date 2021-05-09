#include<bits/stdc++.h>
using namespace std;

#define MAX 9999    // Considered distance to be INF
#define max 5       // max. no of vertices

void dijkstra(int G[max][max],int n,int startnode)
{
    int vweight[max][max],distance[max],prediction[max];
    int visited[max],count,mindistance,nextnode,i,j;
    
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
		{   
			if(G[i][j]==0)
			{
                vweight[i][j]=MAX;  // If there is no edge, distance initialized with infinity
			}
            else 
			{
                vweight[i][j] = G[i][j];
            }
		}
	}    
    for(i=0;i<n;i++)
    {
        distance[i]=vweight[startnode][i];
        prediction[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
	// Find shortest path for all vertices
    while(count<n-1)
    {
        mindistance=MAX;
        
        for(i=0;i<n;i++)
		{
			if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
		}
       
        visited[nextnode]=1;
        
        for(i=0;i<n;i++)
        {
			if(!visited[i])
			{
				if(mindistance+vweight[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+vweight[nextnode][i];
                    prediction[i]=nextnode;
                }
			}
        }
        count++;
    }
    
    for(i=0;i<n;i++)
	{
		if(i!=startnode)
        {
            cout<<"\nDistance of node"<<i<<"="<<distance[i];
            cout<<"\nPath="<<i;
            j=i;
            
            do 
            {
                j=prediction[j];
                cout<<"<-"<<j;
            }
            while(j!=startnode);
        }
	}
}

int main()
{
   // Adjacency Matrix for the given graph
   int G[max][max]={{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}}; 
   int n=5; // No. of vertices
   int u=0; // Source Node
   dijkstra(G,n,u);
   return 0;
}