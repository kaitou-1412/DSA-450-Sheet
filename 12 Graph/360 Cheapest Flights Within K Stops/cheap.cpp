//Bellman Ford
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> dp(n, INT_MAX);
    int i, j, m, cost, u, v;
    m = flights.size();
    dp[src] = 0;
    for (i = 0; i < k + 1; i++)
    {
        vector<int> temp = dp;
        for (j = 0; j < m; j++)
        {
            u = flights[j][0];
            v = flights[j][1];
            cost = flights[j][2];
            if (temp[u] == INT_MAX)
                continue;
            dp[v] = min(dp[v], cost + temp[u]);
        }
    }
    if (dp[dst] == INT_MAX)
        return -1;
    return dp[dst];
}