void order(node *root, vector<node *> &v)
{
    if (root == NULL)
        return;
    order(root->left, v);
    v.push_back(root);
    order(root->right, v);
}

void populateNext(struct node *p)
{
    vector<node *> v;
    order(p, v);
    for (int i = 0; i < v.size() - 1; i++)
    {
        node *temp = v[i];
        temp->next = v[i + 1];
    }
}