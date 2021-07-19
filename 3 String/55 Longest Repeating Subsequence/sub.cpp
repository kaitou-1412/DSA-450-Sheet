//Longest Repeating Subsequence
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int LongestRepeatingSubsequence(string str)
{
    string s1 = str, s2 = str;
    int n = str.size();
    int L[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1] && (i != j))
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[n][n];
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        cout << LongestRepeatingSubsequence(n) << "\n";
    }
    return 0;
}