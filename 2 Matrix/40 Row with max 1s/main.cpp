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

int rowWithMax1s(vector<vector<int> > arr, int n, int m)
{
    int row = -1, ones = 0, c;
    for(int i=0; i<n; i++)
    {
        c = count(arr[i].begin(), arr[i].end(), 1);
        if(ones < c)
        {
            ones = c;
            row  = i;
        }
    }
    return row;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int r, c;
        cin >> r >> c;
        vvi matrix;
        vi v;
        int ele;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                cin >> ele;
                v.pb(ele);
            }
            matrix.pb(v);
            v.clear();
        }
        cout << rowWithMax1s(matrix, r, c) << "\n";
    }
    return 0;
}
