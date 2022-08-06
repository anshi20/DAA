/*
Leetcode Easy 521. Longest Uncommon Subsequence I
Given two strings a and b, return the length of the longest uncommon subsequence between a and b.
If the longest uncommon subsequence does not exist, return -1.

An uncommon subsequence between two strings is a string that is a subsequence of one but not the other.

Eg  :
Input: a = "aba", b = "cdc"
Output: 3
Explanation: One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
Note that "cdc" is also a longest uncommon subsequence.
Example 2:

Input: a = "aaa", b = "bbb"
Output: 3
Explanation: The longest uncommon subsequences are "aaa" and "bbb".
*/

class Solution {
public:
    int findLUSlength(string a, string b) {
       int dp[101][101];
       for(int i=0; i <= a.size();i++){
          for(int j=0;j <= b.size();j++){
              if(i==0||j==0){
                 dp[i][j] = 0;
               }
              else{
                 if(a[i-1]!=b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                  }
                 else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                  }     
              }
           }
       }
      int ans=dp[a.size()][b.size()];
      int lengthy = max(a.size(),b.size());
      if(a==b)
          return -1;
      else
      {
          ans = max(ans,lengthy);
      }
      return ans;
    }
};
