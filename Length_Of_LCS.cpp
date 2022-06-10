#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int m, int n, vector<vector<int>>& dp)
{
	if(m==0||n==0)
	{
	    return 0;
	}
	if(x[m-1]==y[n-1])
	{
		return dp[m][n] = 1 + lcs(x,y,m-1,n-1,dp);
	}
	if(dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	return dp[m][n]=max(lcs(x,y,m,n-1,dp),lcs(x,y,m-1,n,dp));
}

int main()
{
    string x,y;
    cout<<"Enter first string : ";
    cin>>x;
	int m = x.length();
	cout<<"Enter second string : ";
    cin>>y;
	int n = y.length();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
	cout << "\nLength of LCS is : " << lcs(x, y, m, n, dp);
	return 0;
}
