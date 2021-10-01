//Longest Palindrome in a String
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

void printSubStr(
    string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
    cout << "\n";
}

void longestPalSubstr(string str)
{

    int n = str.size();
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
    int start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = true;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    for (int i = 0; i <= n - maxLength; i++)
    {
        if (table[i][maxLength + i - 1])
        {
            start = i;
            break;
        }
    }
    printSubStr(str, start, start + maxLength - 1);
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        longestPalSubstr(str);
    }
    return 0;
}
