
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
const int N = 1e5 + 2;
bool visited[N];
vector<vi> adj(N);
void dfs(int node)
{
    visited[node]=true;
    cout<<node<<" ";
    for(int x:adj[node])
    {
        if(visited[x]);
        else
        {
            dfs(x);
        }
    }
}
int main()
{
    int n,m;
    
    
    int i;
    for(i=0;i<N;i++)
    {
        visited[i] = false;
    }
    cout<<"Enter no. of nodes : ";
    cin>>n;
    cout<<"Enter no. of edges : ";
    cin>>m;
    cout<<"Enter edges : \n";
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    return 0;
}
