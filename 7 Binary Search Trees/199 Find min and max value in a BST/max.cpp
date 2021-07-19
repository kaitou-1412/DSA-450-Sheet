//Function to find the maximum element in the given BST.
int maxValue(Node *root)
{
    // Code here
    if (!root)
        return -1;
    while (root->right)
        root = root->right;
    return root->data;
}