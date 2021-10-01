#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

bool areIsomorphic(string str1, string str2)
{
    // Your code here
    int n = str1.length(), m = str2.length();
    if (n != m)
        return false;
    unordered_map<char, char> mp;
    unordered_set<char> us;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (mp.find(str1[i]) == mp.end() && us.find(str2[j]) == us.end())
        {
            mp[str1[i]] = str2[j];
            us.insert(str2[j]);
        }
        else if (mp.find(str1[i]) == mp.end() && us.find(str2[j]) != us.end())
            return false;
        else
        {
            if (mp[str1[i]] != str2[j])
                return false;
        }
    }
    return true;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if(areIsomorphic(s1, s2)) cout << "Isomorphic\n";
        else cout << "Not Isomorphic\n";
    }
    return 0;
}