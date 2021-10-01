//Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
        visited[i] = false;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    vector<int> ans;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        ans.push_back(i);
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (!visited[adj[i][j]])
            {
                visited[adj[i][j]] = true;
                q.push(adj[i][j]);
            }
        }
    }
    return ans;
}
