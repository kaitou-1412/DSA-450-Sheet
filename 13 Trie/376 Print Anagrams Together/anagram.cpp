vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // Your Code Here
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < string_list.size(); i++)
    {
        string data = string_list[i];

        sort(data.begin(), data.end());

        mp[data].push_back(string_list[i]);
    }

    vector<vector<string>> res;
    for (auto x : mp)
    {
        res.push_back(x.second);
    }

    return res;
}