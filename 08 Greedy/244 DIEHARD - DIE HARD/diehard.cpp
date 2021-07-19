#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int dp[1001][1001];

int survive(int h, int a, int i)
{
    if(h<=0 || a<=0)
        return 0;
    if(dp[h][a] != -1)
        return dp[h][a];
    int x = 0, y = 0, z = 0;
    if(i!=1) x = 1 + survive(h+3, a+2, 1);
    if(i!=2) y = 1 + survive(h-5, a-10, 2);
    if(i!=3) z = 1 + survive(h-20, a+5, 3);
    return dp[h][a] = max({x,y, z});
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int h, a;
        cin >> h >> a;
        memset(dp, -1, sizeof(dp));
        cout << max({survive(h + 3, a + 2, 1), survive(h - 5, a - 10, 2), survive(h - 20, a + 5, 3)}) << "\n";
    }
    return 0;
}
