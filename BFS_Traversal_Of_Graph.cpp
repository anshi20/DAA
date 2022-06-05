
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
const int N = 1e5 + 2;
int main()
{
    int n,m;
    vi adj[N];
    bool visited[N];
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
    queue<int> q;
    q.push(1);
    visited[1]=true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int x: adj[node])
        {
            if(visited[x]==false)
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return 0;
}
