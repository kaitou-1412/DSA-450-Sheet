/*You are required to complete below method */
void deadEnd(Node *root, int l, int r, bool &flag)
{
    if (!root)
        return;
    if (flag)
        return;
    if (!root->left && !root->right)
    {
        if (l == r)
            flag = true;
        return;
    }
    deadEnd(root->left, l, root->data - 1, flag);
    deadEnd(root->right, root->data + 1, r, flag);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    bool flag = false;
    deadEnd(root, 1, INT_MAX, flag);
    return flag;
}