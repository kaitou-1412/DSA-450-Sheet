#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        long long k;
        long long small;
        cin >> n >> q;
        vector<pair<long long, long long>> v;
        for (int i = 0; i < n; i++)
        {
            long long x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end());
        int idx = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[idx].second >= v[i].first)
                v[idx].second = max(v[idx].second, v[i].second);
            else
            {
                idx++;
                v[idx] = v[i];
            }
        }
        for (int i = 0; i < q; i++)
        {
            cin >> k;
            small = -1;
            for (int i = 0; i <= idx; i++)
            {
                if (k <= v[i].second - v[i].first + 1)
                {
                    small = v[i].first + k - 1;
                    break;
                }
                else
                    k -= v[i].second - v[i].first + 1;
            }
            cout << small << "\n";
        }
        cout << "\n";
    }
    return 0;
}
