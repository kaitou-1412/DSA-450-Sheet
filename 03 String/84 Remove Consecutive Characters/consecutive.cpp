#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

string removeConsecutiveCharacter(string S)
{
    // code here.
    if (S.length() == 1)
        return S;
    string s = "";
    s += S[0];
    for (int i = 1; i < S.length(); i++)
    {
        if (S[i] != S[i - 1])
            s += S[i];
    }
    return s;
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
        cout << removeConsecutiveCharacter(s) << "\n";
    }
    return 0;
}
