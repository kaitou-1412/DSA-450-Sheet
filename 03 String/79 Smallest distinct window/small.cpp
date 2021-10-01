#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

string findSubString(string str)
{
    std::unordered_map<char, int> m;
    for (auto c : str) 
    {
        m.insert(pair<char, int>(c, 0));
    }
    int start = 0;
    int end = 0;
    int min_size = INT_MAX;
    int count = 0;
    while (end != str.size()) 
    {
        char c = str[end];
        if (m[c] == 0) 
        {
            count++;
        }
        m[c] += 1;
        if (count == m.size()) 
        {
            while ((m[str[start]] - 1) > 0) 
            {
                m[str[start]] -= 1;
                start++;
            }
            if (min_size > (end - start + 1)) 
            {
                min_size = end - start + 1;
            }
        }
        end++;
    }
    //Get the sub str b/w start and end index
    string subString = str.substr(start, min_size);
    return subString;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << findSubString(s) << "\n";
    }
    return 0;
}
