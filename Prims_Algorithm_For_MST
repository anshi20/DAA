#include <bits/stdc++.h>
using namespace std;

//#define V 5
int graph[10][10];

int min_Key(int key[], bool Mst_Set[], int V)
{
   
    int min_index;
    int min=INT_MAX;
    int i;
    for(i=0;i<V;i++)
    {
        if(key[i]<min && Mst_Set[i]==false)
        {
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

void printMst(int graph[][10], int parent[], int V)
{
    int i;
    cout<<"Edge -- Weight\n";
    for(i=1;i<V;i++)
    {
        cout<<parent[i]<<" -> "<<i<<"\t"<<graph[i][parent[i]]<<endl; 
    }
}

void prims(int graph[][10], int V)
{
    int i,j,v;
    int parent[V];
    int key[V];
    bool Mst_Set[V];
    for(i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        Mst_Set[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(j=0;j<V-1;j++)
    {
        int u = min_Key(key,Mst_Set,V); 
        Mst_Set[u] = true;
        for(v=0;v<V;v++)
        {
            if(graph[u][v]&&Mst_Set[v]==false&&graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    printMst(graph,parent,V);
}

int main()
{
    int i,j,V,m;
    
    cout<<"Enter no. of vertices : (Max 10)";
    cin>>V;
    
    cout<<"\nEnter no. of edges : ";
    cin>>m;
    cout<<"\nEnter edges of graph : ";
    
    
    for(i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[a][b]=w;
        graph[b][a]=w;
    }

    prims(graph,V);
    return 0;
}
