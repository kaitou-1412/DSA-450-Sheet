//Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans(V+1, 0);

    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }

    while (!q.empty())
    {
        int td = q.front();
        q.pop();
        for (auto x : adj[td])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
                ans[x] = ans[val] + 1;
            }
        }
    }

    return ans;
}