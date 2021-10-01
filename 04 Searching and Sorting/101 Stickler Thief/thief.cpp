#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long int
//while(str.length()==0) getline(cin, str);
//str = "";

ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    // ll sum1 = 0, sum2 = 0;
    // for(int i=0; i<n; i++)
    // {
    //     if(i%2 == 0)
    //         sum1 += arr[i];
    //     else
    //         sum2 += arr[i];
    // }
    // return max(sum1, sum2);
    if (n == 1)
        return arr[0];
    if (n == 2)
        return max(arr[0], arr[1]);
    ll dp[n + 1];
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
    }
    return dp[n];
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
