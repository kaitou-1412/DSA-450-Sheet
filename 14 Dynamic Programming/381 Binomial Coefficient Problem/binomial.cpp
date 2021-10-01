int nCr(int n, int r)
{
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
            }
        }
    }
    return dp[n][r];
    // int dp[r+2]={0};
    // const int mod= 1e9+7;
    // dp[0]=1;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=min(r,i);j>=1;j--)
    //         dp[j]=(dp[j]+dp[j-1])%mod;
    // }
    // return dp[r];
}