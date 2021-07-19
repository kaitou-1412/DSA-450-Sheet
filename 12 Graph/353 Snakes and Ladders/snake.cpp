vector<int> findCoordinates(int curr, int n)
{
    int r = n - 1 - (curr - 1) / n;
    int c = (curr - 1) % n;
    if (r % 2 == n % 2)
        c = n - 1 - c;
    vector<int> res = {r, c};
    return res;
}
int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    int steps = 0;
    queue<int> q;
    q.push(1);
    vector<vector<bool>> visited;
    for (int i = 0; i < n; i++)
    {
        vector<bool> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(false);
        }
        visited.push_back(v);
    }
    visited[n - 1][0] = true;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front();
            q.pop();
            if (x == n * n)
                return steps;
            for (int k = 1; k <= 6; k++)
            {
                if (k + x > n * n)
                    break;
                vector<int> pos = findCoordinates(k + x, n);
                int r = pos[0];
                int c = pos[1];
                if (visited[r][c] == true)
                    continue;
                visited[r][c] = true;
                if (board[r][c] == -1)
                    q.push(k + x);
                else
                    q.push(board[r][c]);
            }
        }
        steps++;
    }
    return -1;
}