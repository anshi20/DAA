//0-1 Knapsack Greedy Approach


#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
   double d1 =(double)p1.first/p1.second;
   double d2 =(double)p2.first/p2.second;
   
   return d1>d2;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<pair<int,int>> v(n);
    int i;
    cout<<"\nEnter Values : ";
    for(i=0;i<n;i++)
    {
        cin>>v[i].first;
    }
    cout<<"\nEnter Weight : ";
    for(i=0;i<n;i++)
    {
        cin>>v[i].second;
    }
    cout<<endl;
    sort(v.begin(), v.end(), compare);
    cout<<"\nEnter weight of knapsack : ";
    int w;
    cin>>w;
    int ans=0;
    for(i=0;i<n;i++)
    {
       if(w>v[i].second)
       {
           ans+=v[i].first;
           w-=v[i].second;
       }
    }
    cout<<"\nAnswer is : "<<ans;
    cout<<endl;
    return 0;
}



/*
n=3
values : 60 100 120 
weight : 10 20  30
weight of knapsack : 50
ans : 160
*/
