#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long int
//while(str.length()==0) getline(cin, str);
//str = "";

ll findSubarray(vector<ll> arr, int n)
{
    //code here
    ll sum = 0;
    ll count = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp[sum])
            count += mp[sum];
        mp[sum]++;
    }
    return count;
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

        cout << "\n";
    }
    return 0;
}
