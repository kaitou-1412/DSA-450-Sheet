// Bellman Ford Algorithm
int isNegativeWeightCycle(int N, vector<vector<int>> edges)
{
    // Code here
    vector<int> dist(N, INT_MAX);
    dist[0] = {0};
    for (int i = 0; i < N - 1; i++)
    {
        bool notUpdate = true;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                notUpdate = false;
            }
        }
        if (notUpdate)
        {
            break;
        }
    }
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if (dist[v] > dist[u] + weight)
        {
            return true;
        }
    }
    return false;
}