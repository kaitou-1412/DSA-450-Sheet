#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int

class Solution
{
    public:
        long long int countPS(string str)
        {
            long long int mod = 1000000007;
            long long int N = str.length();
            long long int cps[N + 1][N + 1];
            memset(cps, 0, sizeof(cps));
            for (int i = 0; i < N; i++)
                cps[i][i] = 1;
            for (int L = 2; L <= N; L++)
            {
                for (int i = 0; i <= N - L; i++)
                {
                    int k = L + i - 1;
                    if (str[i] == str[k])
                        cps[i][k] = ((cps[i][k - 1] % mod) + (cps[i + 1][k] % mod) + 1 + mod) % mod;
                    else
                        cps[i][k] = ((cps[i][k - 1] % mod) + (cps[i + 1][k] % mod) - (cps[i + 1][k - 1] % mod) + mod) % mod;
                }
            }
            return cps[0][N - 1];
        }
};

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        lli ans = ob.countPS(str);
        cout << ans << "\n";
    }
    return 0;
}
