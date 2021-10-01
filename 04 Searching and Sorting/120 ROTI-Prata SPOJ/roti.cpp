#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int solve(int *a, int n, int p, int mid)
{
    int time = 0;
    int paratha = 0;
    for(int i = 0; i<n; i++)
    {
        time = a[i];
        int j = 2;
        while(time<=mid)
        {
            paratha++;
            time += a[i]*j;
            j++;
        }
        if(paratha>=p) return 1;
    }
    return 0;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int p, n;
        cin >> p;
        cin >> n;
        int rank[n];
        for(int i=0; i<n; i++) cin >> rank[i];
        int ans = 0;
        int lb = 0;
        int ub = 1e8;
        while(lb<=ub)
        {
            int mid = (lb+ub)/2;
            if(solve(rank, n, p, mid))
            {
                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
