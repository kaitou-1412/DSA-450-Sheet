//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
    // your code goes here
    int count = 0;
    if (!root)
        return count;
    if (l <= root->data && root->data <= h)
        count++;
    count += getCount(root->left, l, h);
    count += getCount(root->right, l, h);
    return count;
}