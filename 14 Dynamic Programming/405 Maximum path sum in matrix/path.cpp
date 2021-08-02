int maximumPath(int N, vector<vector<int>> mat)
{
    // code here
    for (int i = 1; i < N; i++)
    {
        mat[i][0] += max(mat[i - 1][0], mat[i - 1][1]);
        for (int j = 1; j < N - 1; j++)
        {
            mat[i][j] += max(mat[i - 1][j - 1], max(mat[i - 1][j], mat[i - 1][j + 1]));
        }
        mat[i][N - 1] += max(mat[i - 1][N - 2], mat[i - 1][N - 1]);
    }
    int res = INT_MIN;
    for (int j = 0; j < N; j++)
    {
        res = max(res, mat[N - 1][j]);
    }
    return res;
}