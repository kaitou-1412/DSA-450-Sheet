#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int main()
{
    boost;
    int C;
    cin >> C;
    for(int c = 1; c<=C; c++)
    {
        int n, k, b, t;
        cin >> n >> k >> b >> t;
        int x[n] = {0};
        int v[n] = {0};
        for(int i = 0; i<n; i++)
            cin >> x[i];
        for(int i = 0; i<n; i++)
            cin >> v[i];
        int count = 0, cant_reach = 0, swap = 0;
        for(int i = n-1; i>=0; i--)
        {
            int distance = b - x[i];
            int can_cover = t*v[i];
            if(distance<=can_cover)
            {
                count++;
                if(cant_reach>0)
                    swap += cant_reach;
            }
            else
                cant_reach++;
            if(count == k)
                break;
        }
        if(count<k)
            cout << "Case #" << c << ": IMPOSSIBLE\n";
        else
            cout << "Case #" << c << ": " << swap << "\n";
    }
    return 0;
}
