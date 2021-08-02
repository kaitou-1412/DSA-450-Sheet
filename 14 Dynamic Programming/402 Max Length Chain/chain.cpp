int maxChainLen(struct val p[], int n)
{
    //Your code here
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({p[i].first, p[i].second});
    sort(v.begin(), v.end());
    int arr[n], s[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = v[i].first;
        s[i] = v[i].second;
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