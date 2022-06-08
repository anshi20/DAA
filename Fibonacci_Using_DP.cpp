// Time Complexity using DP : O(n)  
// It's far better than recursive code having O(2^n)

#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,i;
  
  cout<<"Enter n : ";
  cin>>n;
  
  vector<int> dp(n+1);
  
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;
  for(i=3;i<=n;i++)
  {
      dp[i] = dp[i-1] + dp[i-2];
  }
  cout<<"\nRequired fibonnaci no. is "<<dp[n];
  return 0;
}
