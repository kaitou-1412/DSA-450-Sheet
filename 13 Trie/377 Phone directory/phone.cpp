struct trie
{
    trie *child[26];
    int val = 0;
    trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
            val = 0;
        }
    }
};

void insert(trie *root, string s)
{
    for (auto x : s)
    {
        int cur = x - 'a';
        if (root->child[cur] == nullptr)
        {
            root->child[cur] = new trie();
        }
        root = root->child[cur];
    }
    root->val = 1;
}

vector<string> res;
string str;

void dfs(trie *root)
{
    if (root->val == 1)
    {
        res.push_back(str);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            str += char(i + 'a');
            dfs(root->child[i]);
            str.pop_back();
        }
    }
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    vector<string> pro;
    for (int i = 0; i < n; i++)
    {
        pro.push_back(contact[i]);
    }
    trie *root = new trie();
    vector<vector<string>> ans;
    for (auto x : pro)
    {
        insert(root, x);
    }
    for (char x : s)
    {
        if (root->child[x - 'a'] != nullptr)
        {
            str = "";
            res.clear();
            dfs(root->child[x - 'a']);
            ans.push_back(res);
            root = root->child[x - 'a'];
        }
        else
        {
            break;
        }
    }
    int i = 0;
    string fin = "";
    for (auto &x : ans)
    {
        fin += s[i++]; //adding the prefixes of the search word
        for (string &st : x)
        {
            st = fin + st;
        }
    }
    while (ans.size() < s.size())
    {
        ans.push_back({{"0"}});
    }
    return ans;
}