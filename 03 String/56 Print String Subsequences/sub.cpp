//Print all subsequences of a string
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int main()
{
    boost;
    string t;
    cin >> t;
    int n = t.size();
    int upper = 1 << n;
    string substr = "";
    for(int i = 1; i<=upper; i++)
    {
        substr = "";
        for(int j = 0; j<n; j++)
        {
            if((1 << j) & i) substr += t[j];
        }
        cout << substr << "\n";
    }
    return 0;
}