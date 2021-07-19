void solve(vector<string> &v, int n, vector<string> &dict, string s, int index, int len, string str)
{
    if (index == len)
    {
        str.pop_back();
        v.push_back(str);
    }
    else
    {
        for (int i = index; i < len; i++)
        {
            if (find(dict.begin(), dict.end(), s.substr(index, i - index + 1)) != dict.end())
            {
                string temp = s.substr(index, i - index + 1) + ' ';
                solve(v, n, dict, s, i + 1, len, str + temp);
            }
        }
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    // code here
    vector<string> v;
    solve(v, n, dict, s, 0, s.length(), "");
    return v;
}