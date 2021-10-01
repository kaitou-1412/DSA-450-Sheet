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
    while(t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        int a[n+2] = {0};
        int b[n+2] = {0};
        for(int i=1; i<=n; i++)
            cin >> a[i] >> b[i];
        a[n+1]  = w+1;
        b[n+1] = h+1;
        sort(a, a+n+2);
        sort(b, b+n+2);
        int x = 0, y = 0;
        for(int i = 1; i<=n+1; i++)
        {
            x = max(x, a[i] - a[i-1] - 1);
            y = max(y, b[i] - b[i-1] - 1);
        }
        int res = x*y;
        cout << res << "\n";
    } 
    return 0;
}

