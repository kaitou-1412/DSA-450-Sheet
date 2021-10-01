vector<int> rightView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        Node *t;
        while (sz--)
        {
            t = q.front();
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        ans.push_back(t->data);
    }
    return ans;
}