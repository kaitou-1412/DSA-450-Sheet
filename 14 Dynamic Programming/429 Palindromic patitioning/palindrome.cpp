int helper(string &s, int start, int end, vector<vector<int>> &dp, vector<vector<int>> &isPalindrom)
{
    if (isPalindrom[start][end] == 1)
    {
        return dp[start][end] = 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int ans = INT_MAX;
    for (int i = start; i < end; i++)
    {
        if (dp[start][i] == -1)
        {
            dp[start][i] = helper(s, start, i, dp, isPalindrom);
        }
        if (dp[i + 1][end] == -1)
        {
            dp[i + 1][end] = helper(s, i + 1, end, dp, isPalindrom);
        }
        ans = min(ans, dp[start][i] + dp[i + 1][end] + 1);
    }
    return dp[start][end] = ans;
}
int palindromicPartition(string str)
{
    int n = str.length();
    vector<vector<int>> isPalindrom(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        isPalindrom[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        isPalindrom[i][i + 1] = (str[i] == str[i + 1]);
    }
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i <= n - k; i++)
        {
            int j = i + k - 1;
            isPalindrom[i][j] = (str[i] == str[j] && isPalindrom[i + 1][j - 1]);
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(str, 0, n - 1, dp, isPalindrom);
}