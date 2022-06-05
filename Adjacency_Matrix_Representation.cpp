
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
    cout<<"\nEnter edges of graph : ";
    vvi adjm(n+1, vi(n+1,0));
    vvi adjm2(n+1, vi(n+1,0));
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adjm[a][b]=1;
        adjm[b][a]=1;
        adjm2[a][b]=1;
    }
    cout<<"\nADJACENCY MATRIX  --  UNDIRECTED GRAPH\n";
    for(i=1;i<n+1;i++)
     {
          for(j=1;j<n+1;j++)
          {
              cout<<adjm[i][j]<<" ";
          }
          cout<<endl;
     }
    cout<<"\nADJACENCY MATRIX  --  DIRECTED GRAPH\n";
    for(i=1;i<n+1;i++)
     {
          for(j=1;j<n+1;j++)
          {
              cout<<adjm2[i][j]<<" ";
          }
          cout<<endl;
     }
    return 0;
}
