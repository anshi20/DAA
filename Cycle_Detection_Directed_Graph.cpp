#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define bi vector<bool>

bool iscycle(int src, vvi &adj, bi &visited, bi &stack)
{
    stack[src] = true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i : adj[src])
        {
            if(!visited[i] and iscycle(i,adj,visited,stack))
                return true;
            if(stack[i])
                return true;
        }
    }
    stack[src]=false;
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
    }
    bi stack(n,false);
    for(i=0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,stack))
             cycle=true;
    }
    if(cycle)
       cout<<"\nCycle detected!!\n";
    else
       cout<<"\nNo Cycle detected!!\n";
    return 0;
}
