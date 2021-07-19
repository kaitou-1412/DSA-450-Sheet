//Function to check whether a Binary Tree is BST or not.
bool isBSTUtil(Node *root, Node *l = NULL, Node *r = NULL)
{
    // Base condition
    if (root == NULL)
        return true;

    // if left node exist then check it has
    // correct data or not i.e. left node's data
    // should be less than root's data
    if (l != NULL and root->data <= l->data)
        return false;

    // if right node exist then check it has
    // correct data or not i.e. right node's data
    // should be greater than root's data
    if (r != NULL and root->data >= r->data)
        return false;

    // check recursively for every node.
    return isBSTUtil(root->left, l, root) and isBSTUtil(root->right, root, r);
}
bool isBST(Node *root)
{
    Node *l = NULL, *r = NULL;
    return isBSTUtil(root, l, r);
}