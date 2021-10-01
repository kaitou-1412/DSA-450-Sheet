// You are required to complete this function
// A helper function that stores inorder
// traversal of a tree rooted with node
void storeInorder(Node *node, vector<int> &inorder)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    storeInorder(node->left, inorder);

    inorder.push_back(node->data);

    /* now recur on right child */
    storeInorder(node->right, inorder);
}
int countPairs(Node *root1, Node *root2, int x)
{
    // Code here
    vector<int> v1;
    storeInorder(root1, v1);
    vector<int> v2;
    storeInorder(root2, v2);
    int n = v1.size(), i = 0, j = v2.size() - 1;
    int count = 0;
    while (i < n and j >= 0)
    {
        if (v1[i] + v2[j] == x)
        {
            count++;
            i++;
            j--;
        }
        else if (v1[i] + v2[j] < x)
            i++;
        else
            j--;
    }
    return count;
}