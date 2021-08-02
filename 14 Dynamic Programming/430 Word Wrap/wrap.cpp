int solveWordWrap(vector<int> a, int k)
{
    // Code here
    int n = a.size();
    int extraSpaces[n][n], dp[n];
    for (int i = 0; i < n; ++i)
    {
        extraSpaces[i][i] = k - a[i];
        for (int j = i + 1; j < n; ++j)
            extraSpaces[i][j] = extraSpaces[i][j - 1] - a[j] - 1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (extraSpaces[i][j] < 0)
                extraSpaces[i][j] = INT_MAX;
            else if (j == n - 1) //extra spaces are non-negative
                extraSpaces[i][j] = 0;
            else
                extraSpaces[i][j] = extraSpaces[i][j] * extraSpaces[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        dp[i] = extraSpaces[0][i];
        for (int j = 0; j < i; ++j)
        { //dp[j] is subproblem
            if (dp[j] != INT_MAX and extraSpaces[j + 1][i] != INT_MAX)
                dp[i] = min(dp[i], dp[j] + extraSpaces[j + 1][i]);
        }
    }
    return dp[n - 1];
}