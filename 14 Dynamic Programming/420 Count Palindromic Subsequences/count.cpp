long long int countPS(string s)
{
    // Your code here
    int MOD = 1e9 + 7;
    int n = s.size();
    int dp[n][n]{};
    for (int i = n - 1; i >= 0; i--) // ending position
    {
        dp[i][i] = (s[i] == s[i]);
        for (int j = i + 1; j < n; j++) // starting position
        {
            dp[i][j] = (dp[i + 1][j] + dp[i][j - 1]) % MOD;
            if (s[i] == s[j])
                dp[i][j]++;
            else
                dp[i][j] = (MOD + dp[i][j] - dp[i + 1][j - 1]) % MOD;
        }
    }
    return dp[0][n - 1];
}