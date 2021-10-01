void dfs(int src, vector<vector<int>> &g, vector<int> &visited, string &ans)
{
    visited[src] = 1;
    for (auto x : g[src])
    {
        if (!visited[x])
        {
            dfs(x, g, visited, ans);
        }
    }
    char ch = src + 'a';
    ans = ch + ans;
}
string findOrder(string dict[], int n, int k)
{
    //code here
    vector<vector<int>> g(k);
    for (int i = 0; i < n - 1; i++)
    {
        string w1 = dict[i];
        string w2 = dict[i + 1];
        for (int j = 0; j < min(w1.length(), w2.length()); j++)
        {
            if (w1[j] != w2[j])
            {
                g[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }
    vector<int> visited(k, 0);
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        if (!visited[i])
        {
            dfs(i, g, visited, ans);
        }
    }
    return ans;
}