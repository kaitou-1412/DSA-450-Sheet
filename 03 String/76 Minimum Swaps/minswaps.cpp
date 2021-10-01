#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int minimumNumberOfSwaps(string s)
{
    int n = s.size(), ans = 0, open = 0, close = 0, fault = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ']')
        {
            close++;
            fault = close - open;
        }
        else
        {
            open++;
            if (fault > 0)
            {
                ans += fault;
                fault--;
            }
        }
    }
    return ans;
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
        cout << minimumNumberOfSwaps(s) << "\n";
    }
    return 0;
}
