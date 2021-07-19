#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str
int lps(string s)
{
    // Your code goes here
    int len = 0;
    int sz = s.size();
    int lps[sz+1] = {0};
    int i = 1;
    while(i<sz)
    {
        if(s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(len != 0)
        {
            len = lps[len-1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }
    return lps[sz-1];
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
        cout << lps(s) << "\n";
    }
    return 0;
}