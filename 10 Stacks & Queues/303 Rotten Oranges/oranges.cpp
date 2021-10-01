//Function to find minimum time required to rot all oranges.
bool isSafe(vector<vector<int>> &mat, int n, int m, int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1);
}
int rotOranges(vector<vector<int>> &mat, int n, int m)
{
    int timer = -1;

    queue<pair<int, int>> q;

    int x[] = {-1, 1, 0, 0};
    int y[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
            {
                q.push({i, j});

                mat[i][j] = 3;
            }
        }
    }

    while (q.empty() == false)
    {
        int count = q.size();

        for (int k = 0; k < count; k++)
        {
            auto index = q.front();
            int i = index.first;
            int j = index.second;
            for (int index = 0; index < 4; index++)
            {
                if (isSafe(mat, n, m, i + x[index], j + y[index]) == true)
                {
                    q.push({i + x[index], j + y[index]});
                    mat[i + x[index]][j + y[index]] = 3;
                }
            }

            q.pop();
        }

        timer++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return timer;
}
int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    return rotOranges(grid, n, m);
}