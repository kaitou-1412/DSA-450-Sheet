int kadane(vector<int> v, int n)
{
    int ma = INT_MIN;
    int until = 0;
    for (int i = 0; i < n; i++)
    {
        until += v[i];
        if (until > ma)
            ma = until;
        if (until < 0)
            until = 0;
    }
    return ma;
}
int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    // code here
    int ma = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        vector<int> ans(C);
        for (int j = i; j < R; j++)
        {
            for (int col = 0; col < C; col++)
                ans[col] += M[j][col];
            ma = max(ma, kadane(ans, C));
        }
    }
    return ma;
}