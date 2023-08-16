int mod=1e9+7;
int catalan(int n)
{
  int dp[n+1];
  dp[0]=1;
  for(int i=1;i<=n;i++){
    dp[i]=0;
    for(int j=0;j<i;j++)
      dp[i]=(dp[i]+(dp[j]*dp[i-j-1])%mod)%mod;
  }
  return dp[n];
}
