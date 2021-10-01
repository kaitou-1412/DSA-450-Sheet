//Function to check whether a binary tree is balanced or not.
int f = 1;
int solve(Node *root)
{
    if (!root)
        return 0;
    int l = solve(root->left);
    int r = solve(root->right);
    if (abs(l - r) > 1)
        f = 0;
    return (1 + max(l, r));
}
bool isBalanced(Node *root)
{
    //  Your Code here
    f = 1;
    solve(root);
    return f;
}