#include<bits/stdc++.h>

using namespace std;

const int N= 100;
vector<int> parent(N);
vector<int> size(N);

void make_set(int v)
{
    parent[v]=v;
    size[v]=1;
}

int find_set(int v)
{
    if(parent[v]==v)
          return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int u, int v)
{
    int a = find_set(u);
    int b = find_set(v);
    if(a!=b)
    {
        if(size[a]<size[b])
        {
            swap(a,b);
        }
        parent[b]=parent[a];
        size[a]+=size[b];
    }
}

int main()
{
    
    int i;
    for(i=0;i<N;i++)
    {
        make_set(i);
    }
    vector<vector<int>> edges;
    int m,n;
    cout<<"enter no. of vertices :";
    cin>>n;
    cout<<"\nenter no. of edges :";
    cin>>m;
    for(i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    bool cycle = false;
    for(auto i : edges)
    {
        int u = i[0]; 
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if(x==y)
        {
            cycle=true;
        }
        else
            union_set(x,y);
    }
    if(cycle)
       cout<<"Cycle is present !";
    else
       cout<<"Cycle is not present!";
    return 0;
}

