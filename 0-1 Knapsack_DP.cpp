
#include <bits/stdc++.h>

using namespace std;

int dp[10][10];
int p[10];
int wt[10];

int Knapsack(int n, int w)
{
    if(w<=0)
       return 0;
    if(n<=0)
       return 0;
    if(dp[n][w]!=-1)
       return dp[n][w];
    if(wt[n-1]>w)
       dp[n][w] = Knapsack(n-1,w);
    dp[n][w] = max(Knapsack(n-1,w) , Knapsack(n-1,w-wt[n-1]) + p[n-1]); 
    return dp[n][w];
}

int main()
{
    int w,i,j,n;
    cout<<"Enter no. of items : ";
    cin>>n;
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<"\nWeight : ";
    for(i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"\nProfit : ";
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"\nEnter weight of knapsack : ";
    cin>>w;
    cout<<"\nMAX PROFIT : "<<Knapsack(n,w);
    cout<<"\n";
    return 0;
}
