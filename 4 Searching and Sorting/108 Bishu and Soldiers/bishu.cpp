#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int main()
{
    boost;
    int n, q, ele;
    cin >> n;
    vector<int> power(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        power[i] = ele;
    }
    sort(power.begin(), power.end());
    vector<int> pref;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += power[i];
        pref.push_back(sum);
        mp[power[i]] = i + 1;
    }
    cin >> q;
    int bishu;
    for (int i = 0; i < q; i++)
    {
        cin >> bishu;
        if (bishu < power[0])
            cout << "0 0\n";
        else if (bishu > power[n - 1])
            cout << n << " " << pref[n - 1] << "\n";
        else
            cout << mp[bishu] << " " << pref[mp[bishu] - 1] << "\n";
    }
    cout << "\n";
    return 0;
}
