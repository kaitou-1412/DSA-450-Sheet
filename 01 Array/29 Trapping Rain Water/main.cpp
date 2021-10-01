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
        int n, total = 0;
        cin >> n;
        int a[n];
        ip(a, n);
        int arr1[n] = {0}, arr2[n] = {0};
        arr1[0] = a[0];
        arr2[n-1] = a[n-1];
        for(int i=1; i<n; i++)
            arr1[i] = max(arr1[i-1], a[i]);
        for(int i=n-2; i>=0; i--)
            arr2[i] = max(arr2[i+1], a[i]);
        for(int i=0; i<n; i++)
            total += min(arr1[i], arr2[i]) - a[i];
        cout << total << "\n";
    }
    return 0;
}
