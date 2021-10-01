// Unbounded Knapsack
int minimumCost(int cost[], int N, int W)
{
    // Your code goes here
    vector<vector<int>> dp(W + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = INT_MAX;
            else
            {
                if (cost[j - 1] != -1 && j <= i && dp[i - j][j] != INT_MAX)
                    dp[i][j] = min(dp[i][j - 1], cost[j - 1] + dp[i - j][j]);
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[W][N] != INT_MAX ? dp[W][N] : -1;
}