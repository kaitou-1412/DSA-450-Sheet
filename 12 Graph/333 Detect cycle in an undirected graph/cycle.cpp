bool DFS(int u, int p, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;
    for (auto i : adj[u])
    {
        if (!visited[i])
        {
            if (DFS(i, u, adj, visited))
                return true;
        }
        else if (i != p || i == u)
            return true;
    }
    return false;
}
//Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> visited(V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && DFS(i, -1, adj, visited))
            return true;
    }
    return false;
}