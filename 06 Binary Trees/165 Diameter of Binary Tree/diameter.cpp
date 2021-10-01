int ma;
int func(Node *root)
{
    if (!root)
        return 0;
    int x = func(root->left);
    int y = func(root->right);
    ma = max(ma, x + y + 1);
    return (1 + max(x, y));
}
int diameter(Node *root)
{
    ma = INT_MIN;
    int x = func(root);
    return ma;
}