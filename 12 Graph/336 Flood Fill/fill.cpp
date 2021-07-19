void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &image, int newColor, int N, int M, int oldColor)
{
    if (i < 0 or j < 0 or i >= N or j >= M)
        return;
    if (visited[i][j] or image[i][j] != oldColor)
        return;
    visited[i][j] = true;
    image[i][j] = newColor;
    dfs(i + 1, j, visited, image, newColor, N, M, oldColor);
    dfs(i - 1, j, visited, image, newColor, N, M, oldColor);
    dfs(i, j + 1, visited, image, newColor, N, M, oldColor);
    dfs(i, j - 1, visited, image, newColor, N, M, oldColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int N = image.size(), M = image[0].size();
    int oldColor = image[sr][sc];
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    dfs(sr, sc, visited, image, newColor, N, M, oldColor);
    return image;
}