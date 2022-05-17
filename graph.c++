#include<bits/stdc++.h>
#include<list>
using namespace std;
class graph
{
  int v;
  list<int> *adjList;
  void DFS_util(int v, bool visited[]);
  public : 
    graph(int v)
    {
      this->v=v;
      adjList=new list<int>[v];
    }
    void addEdge(int u, int v)
    {
      adjList[u].push_back(v);
    }
    void DFS();
};
void graph :: DFS_util(int v, bool visited[])
{
   visited[v] = true;
   cout<<v<<" ";
   list<int> :: iterator i;
   for(i=adjList[v].begin();i!=adjList[v].end();i++)
   {
     if(!visited[*i])
        {
          DFS_util(*i,visited); 
        }  
   }
}
void graph :: DFS()
{
 bool *visited=new bool[v];
 int i;
 for(i=0;i<v;i++)
  {
    visited[i]=false; 
  }
 for(i=0;i<v;i++)
  {
    if(visited[i]==false)
       {
          DFS_util(i,visited);
       }
  }
}
int main()
{
 graph g(5);
 g.addEdge(0,1);
 g.addEdge(0,2);
 g.addEdge(0,3);
 g.addEdge(1,2);
 g.addEdge(2,4);
 g.addEdge(3,3);
 g.addEdge(4,4);
 g.DFS();
 return 0;
}
