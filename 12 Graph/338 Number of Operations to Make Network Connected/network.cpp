void dfs(int src, vector<int> g[], vector<int> &visited)
{
    visited[src] = 1;
    for (auto x : g[src])
    {
        if (!visited[x])
        {
            dfs(x, g, visited);
        }
    }
}
int makeConnected(int n, vector<vector<int>> &edges)
{
    vector<int> g[n];
    int m = edges.size();
    if (m < n - 1)
        return -1;
    for (int i = 0; i < edges.size(); i++)
    {
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(n, 0);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            c++;
            dfs(i, g, visited);
        }
    }
    return c - 1;
}