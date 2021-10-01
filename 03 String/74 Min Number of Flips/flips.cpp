// Min Number of Flips
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int minFlips(string S)
{
    int c1 = 0, c2 = 0;
    int n = S.size();
    if (n == 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            if (S[i] == '0')
                c1++;
            else
                c2++;
        }
        else
        {
            if (S[i] == '1')
                c1++;
            else
                c2++;
        }
    }
    return min(c1, c2);
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
        cout << minFlips(s) << "\n";
    }
    return 0;
}
