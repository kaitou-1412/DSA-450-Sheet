long long dp[10][1005];
int mat[4][3] = {{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9},
                 {-1, 0, -1}};
long long solve(int i, int j, int len)
{
    if (len == 1)
        return 1;
    if (dp[mat[i][j]][len] != -1)
        return dp[mat[i][j]][len];
    long long a = solve(i, j, len - 1);
    long long b = 0, c = 0, d = 0, e = 0;
    if (j - 1 >= 0 && mat[i][j - 1] != -1)
        b = solve(i, j - 1, len - 1);
    if (j + 1 < 3 && mat[i][j + 1] != -1)
        c = solve(i, j + 1, len - 1);
    if (i - 1 >= 0 && mat[i - 1][j] != -1)
        d = solve(i - 1, j, len - 1);
    if (i + 1 < 4 && mat[i + 1][j] != -1)
        e = solve(i + 1, j, len - 1);
    return dp[mat[i][j]][len] = a + b + c + d + e;
}
long long getCount(int n)
{
    // Your code goes here
    dp[10][n + 1];
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] != -1)
                ans += solve(i, j, n);
        }
    }
    return ans;
}