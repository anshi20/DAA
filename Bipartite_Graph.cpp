
#include <bits/stdc++.h>

using namespace std;

vector<int> col;
vector<bool> visited;
vector<vector<int>> adj;
bool bipartite;

void color(int u, int curr)
{
    if(col[u]!=-1 && col[u]!=curr)
        {
            bipartite = false;
            return;
        }
    col[u]=curr;
    if(visited[u])
         return;
    visited[u] = true;
    for(auto i : adj[u])
    {
        color(i,curr xor 1);
    }
}
int main()
{
    bipartite = true;
    int n,m;
    int i;
    cout<<"Enter no. of vertices : ";
    cin>>n;
    cout<<"\nEnter no. of edges : ";
    cin>>m;
    cout<<"\nEnter edges : \nu   v\n-----\n";
    col = vector<int>(n,-1);
    visited = vector<bool>(n,false);
    adj = vector<vector<int>>(n);
    for(i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            color(i,0);
        }
    }
    if(bipartite)
        cout<<"\nGraph is bipartite !!\n";
    else
        cout<<"\nGraph is not bipartite !!\n";
    return 0;
    
}
