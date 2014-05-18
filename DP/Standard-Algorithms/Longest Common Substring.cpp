/* Longest common substring problem can be solved using dynamic programming.
 * Here, the state dp[i][j] stores the length of the longest substring ending in a[i] and b[j].
 */

long long int longest_common_substring(string a, string b)
{
  long long int len_a = a.length();
  long long int len_b = b.length();
  
  long long int ans;
  long long int dp[len_a+1][len_b+1];
  
  for(long long int i=0; i<=len_a; i++)
  {
    for(long long int j=0; j<=len_b; j++)
    {
      if(i==0 || j==0)
        dp[i][j] = 0;
      
      else
      {
        if(a[i-1]==b[j-1]
        {
          dp[i][j] = dp[i-1][j-1] + 1;
          if(dp[i][j]>ans)
            ans = dp[i][j];
        }
        else
          dp[i][j] = 0;
      }
    }
  }
  return ans;
}
