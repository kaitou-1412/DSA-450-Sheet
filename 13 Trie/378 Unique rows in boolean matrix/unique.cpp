struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isEnd = false;
    }
};

bool insert(int arr[], int col, TrieNode *root)
{
    TrieNode *curr = root;
    bool flag = false;
    for (int i = 0; i < col; i++)
    {
        int index = arr[i];
        if (curr->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
            flag = true;
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
    return flag;
}

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int m[MAX][MAX], int row, int col)
{
    //Your code here
    TrieNode *root = new TrieNode();
    vector<vector<int>> res;
    for (int i = 0; i < row; i++)
    {
        if (insert(m[i], col, root) == true)
        {
            vector<int> v;
            for (int j = 0; j < col; j++)
            {
                v.push_back(m[i][j]);
            }
            res.push_back(v);
        }
    }
    return res;
}