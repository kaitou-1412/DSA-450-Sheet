#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//while(str.length()==0) getline(cin, str);
//str = "";
using namespace std;
#define lli long long int
#define ull unsigned long long int
#define fo(i, start, ending) for(i=start;i<ending;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define rtr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
typedef pair<int, int> pii;
typedef pair<lli, lli> pl;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void ip(int a[], int n)
{
    int i;
    fo(i, 0, n) cin >> a[i];
}

void op(int a[], int n)
{
    int i, start = 0, ending = n-1;
    fo(i, start, ending) cout << a[i] << " ";
    cout << a[ending] << "\n";
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n;
        int a[n];
        ip(a, n);
        cin >> k;
        int good = 0;
        for(int i = 0; i<n; i++)
        {
            if(a[i]<=k)
                good++;
        }
        int min_bad = INT_MAX, bad = 0;
        for(int i = 0; i<good; i++)
        {
            if(a[i]>k)
                bad++;
        }
        int i = 0, j = good-1;
        while(j<n)
        {
            min_bad = min(min_bad, bad);
            j++;
            if(j<n && a[j]>k) bad++;
            if(a[i]>k) bad--;
            i++;
        }
        int min_swaps = min_bad;
        cout << min_swaps << "\n";
    }
    return 0;
}
