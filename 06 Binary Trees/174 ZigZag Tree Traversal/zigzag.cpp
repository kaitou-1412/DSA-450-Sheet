vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    int f = 1;
    while (!q.empty())
    {
        vector<int> temp;
        int sz = q.size();
        while (sz--)
        {
            Node *t = q.front();
            q.pop();
            temp.push_back(t->data);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        if (f % 2 == 0)
            reverse(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++)
            ans.push_back(temp[i]);
        f = !f;
    }
    return ans;
}