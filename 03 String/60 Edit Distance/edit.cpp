//Edit Distance
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

// Utility function to find the minimum of three numbers
int min3(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistance(string s, string t)
{
    if(s == t) return 0;
    int m = s.size(), n = t.size();
    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider all
            // possibilities and find the minimum
            else
                dp[i][j] = 1 + min3(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[m][n];
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
        cout << editDistance(s1, s2) << "\n";
    }
    return 0;
}