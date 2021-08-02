// Unbounded Knapsack (Repetition of items allowed)
int knapSack(int n, int w, int val[], int wt[])
{
    // code here
    vector<int> dp(w + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = wt[i]; j <= w; j++)
        {
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    return dp[w];
}