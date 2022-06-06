
#include <bits/stdc++.h>
#define vi vector<int> 
using namespace std;

int main()
{
    int m,n;
    cout<<"enter no of vertices : ";
    cin>>n;
    cout<<"\nEnter no of edges :";
    cin>>m;
    int cnt=0;
    vi adj[n];
    vi in_degree(n,0);
    cout<<"\nEnter edges : \n";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        // u --> v edge
        adj[u].push_back(v);
        in_degree[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(in_degree[i]==0)
           q.push(i);
    }
    while(!q.empty())
    {
        int a = q.front();
        cout<<a<<" ";
        q.pop();
        for(auto i : adj[a])
        {
            in_degree[i]--;
            if(in_degree[i]==0)
                q.push(i);
        }
    }
    return 0;
}
