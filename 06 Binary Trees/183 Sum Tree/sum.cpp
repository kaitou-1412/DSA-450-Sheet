int solve(Node *root, int &f)
{
    if (!root)
        return 0;
    int a = solve(root->left, f);
    int b = solve(root->right, f);
    int x = root->data;
    if (a + b != 0 && root->data != a + b)
        f = 0;
    return a + b + x;
}
bool isSumTree(Node *root)
{
    // Your code here
    if (!root)
        return true;
    int f = 1;
    int x = solve(root, f);
    if (f)
        return true;
    return false;
}