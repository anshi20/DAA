#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define bi vector<bool>

bool iscycle(int src, vvi &adj, bi &visited, int parent)
{
    visited[src] = true;
    for(auto i : adj[src])
    {
        if(i!=parent)
        {
            if(visited[i])
                return true;
            if(!visited[i] and iscycle(i,adj,visited,src))
                return true;
        }
    }
    return false;
}

int main()
{
    int m,n;
    cout<<"Enter no. of vertices : ";
    cin>>n;
    cout<<"\nEnter no. of edges : ";
    cin>>m;
    cout<<"Enter edges : \n";
    int i;
    vvi adj(n);
    bi visited(n,false);
    bool cycle = false;
    for(i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,-1))
             cycle=true;
    }
    if(cycle)
       cout<<"\nCycle detected!!\n";
    else
       cout<<"\nNo Cycle detected!!\n";
    return 0;
}

