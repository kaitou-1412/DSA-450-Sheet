#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

bool solve(lli *a, lli n, lli mid, lli m)
{
    lli s = 0;
    for(int i=0; i<n; i++)
    {
        if(mid <= a[i]) 
            s += a[i] - mid;
    }
    if(s<m) return false;
    return true;
}

int main()
{
    boost;
    lli n, m;
    cin >> n >> m;
    lli a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    lli lb = 0;
    lli ub = *max_element(a, a+n);
    lli ans = 0;
    while(lb<=ub)
    {
        lli mid = (lb+ub)/2;
        if(solve(a, n, mid, m))
        {
            ans = mid;
            lb = mid + 1;
        }
        else
            ub = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}