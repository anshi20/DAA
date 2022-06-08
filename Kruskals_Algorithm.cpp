//  Kruskal's Algorithm to find MST of a graph.
//  Time Complexity : O(ELogV)
//  Space Complexity : O(E+V)

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
    cout<<"\nenter edges : \n";
    cout<<"u"<<" "<<"v"<<" "<<"w"<<endl;
    for(i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    cout<<"\nEdges included in MST are : \n";
    cout<<"u\tv\n";
    for(auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x=find_set(u); 
        int y=find_set(v);
        if(x==y)
           continue;
        else{
           cost+=w;
           cout<<u<<"\t"<<v<<endl;
           union_set(u,v);
        }
    }
    cout<<"\nCost of MST : "<<cost;
    return 0;
}
