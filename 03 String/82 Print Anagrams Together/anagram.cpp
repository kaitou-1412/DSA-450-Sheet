#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // Your Code Here
    int n = string_list.size();
    map<string, vector<int>> m;
    vector<int> v;
    vector<string> words;
    vector<vector<string>> groups;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s = string_list[i];
        sort(s.begin(), s.end());
        m[s].push_back(i);
    }
    map<string, vector<int>>::iterator it;
    vector<int>::iterator it2;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            words.push_back(string_list[*it2]);
        }
        groups.push_back(words);
        words.clear();
    }
    return groups;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {

        // string s;
        // cin >> s;
        
    }
    return 0;
}
