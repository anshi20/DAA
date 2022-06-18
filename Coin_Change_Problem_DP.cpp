#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int N=1e3+2;
int dp[N][N];

int coinProblem(vector<int> &a, int n, int x)
{
    if(x==0)
       return 1;
    if(n<=0||x<0)
       return 0;
    if(dp[n][x]!=-1)
       return dp[n][x];
    dp[n][x]=coinProblem(a,n-1,x)+coinProblem(a,n,x-a[n-1]);
    return dp[n][x];
}

int main()
{
    int i,j,n,x;
    cout<<"Enter no. of coins : ";
    cin>>n;
    cout<<"\nEnter values of coins : \n";
    vector<int> a(n);
    rep(i,0,n) 
       cin>>a[i];
    cout<<"\nEnter required value : ";
    cin>>x;
    rep(i,0,N)
    {
        rep(j,0,N)
        {
            dp[i][j]=-1;
        }
    }
    cout<<"\nAnswer : "<<coinProblem(a,n,x);
    return 0;
}
