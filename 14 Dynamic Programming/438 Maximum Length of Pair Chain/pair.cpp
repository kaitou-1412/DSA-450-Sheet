int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    sort(pairs.begin(), pairs.end());
    int arr[n], s[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = pairs[i][0];
        s[i] = pairs[i][1];
    }
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > s[j] && dp[i] <= dp[j])
                dp[i] = 1 + dp[j];
        }
    }
    return *max_element(dp, dp + n);
}