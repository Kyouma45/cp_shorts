int nCr(int n,int r)
{
  int dp[r+1]={0};
  dp[0]=1;
  for(int i=1;i<=n;i++)
    for(int j=min(i,r);j>0;j--)
      dp[j]=dp[j]+dp[j-1];
  return dp[r];
}
