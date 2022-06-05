
#include <bits/stdc++.h>
#define vi vector<int> 
#define vvi vector<vi> 
#define pi pair<int,int>

using namespace std;

int main()
{
    int i,j,n,m;
    
    cout<<"Enter no. of vertices : ";
    cin>>n;
    cout<<"\nEnter no. of edges : ";
    cin>>m;
    vi adj[10];
    cout<<"\nEnter edges of graph : \n";
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<"\nADJACENCY LIST -- UNDIRECTED GRAPH\n";
    for(i=1;i<n+1;i++)
    {
        cout<<i<<" -> ";
        for(int x: adj[i])
             cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
