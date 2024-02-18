int nCr(int n,int r)
{
  int dp[r+1]={0};
  dp[0]=1;
  for(int i=1;i<=n;i++)
    for(int j=min(i,r);j>0;j--)
      dp[j]=dp[j]+dp[j-1];
  return dp[r];
}

//if needed repeatedly
//use pascal's triangle
vector<vector<long long>> table;
table.resize(n + 1);
for (int i = 0; i < n + 1; ++i)
    table[i] = vector<long long>(i + 1, 1);
    for (int j = 1; j < i; ++j)
        table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;

// nCr=table[n][r]
