//Count and Say
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

string countAndSay(int n)
{
    string say[31];
    say[1] = "1";
    for (int j = 2; j <= 30; j++)
    {
        string s = say[j - 1];
        say[j] = "";
        int count = 0;
        char ch = s[0];
        for (int i = 0; i < s.size(); i++)
        {
            if (ch == s[i])
                count++;
            else
            {
                say[j] += to_string(count) + ch;
                ch = s[i];
                count = 1;
            }
        }
        say[j] += to_string(count) + ch;
    }
    return say[n];
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countAndSay(n) << "\n";
    }
    return 0;
}