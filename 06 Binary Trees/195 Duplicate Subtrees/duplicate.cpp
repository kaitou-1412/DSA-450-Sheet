string inorder(Node *node, unordered_map<string, int> &m, vector<int> &v)
{
    if (!node)
        return "";
    string str = "(";
    str += inorder(node->left, m, v);
    str += to_string(node->data);
    str += inorder(node->right, m, v);
    str += ")";
    if (m[str] == 1)
        v.push_back(node->data);
    m[str]++;
    return str;
}
void printAllDups(Node *root)
{
    // Code here
    vector<int> v;
    unordered_map<string, int> m;
    inorder(root, m, v);
    if (v.size() == 0)
    {
        cout << "-1";
        return;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}