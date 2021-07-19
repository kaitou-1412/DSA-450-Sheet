vector<int> topView(Node *root)
{
    //Your code here
    vector<int> ans;
    if (!root)
        return ans;
    map<int, int> m;            //{horizontal height: -2,-1,0,1,2; value}
    queue<pair<Node *, int>> q; //{Node; horizontal height: -2,-1,0,1,2}
    q.push({root, 0});
    while (!q.empty())
    {
        Node *t = q.front().first;
        int h = q.front().second;
        q.pop();
        if (!m[h])
            m[h] = t->data;
        if (t->left)
            q.push({t->left, h - 1});
        if (t->right)
            q.push({t->right, h + 1});
    }
    for (auto x : m)
        ans.push_back(x.second);
    return ans;
}