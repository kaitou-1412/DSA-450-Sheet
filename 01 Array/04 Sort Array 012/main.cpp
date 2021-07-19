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
    int n, i, j=0;
    cin >> n;
    int a[n];
    ip(a, n);
    fo(i, 0, n)
    {
        if(a[i]==0)
        {
            if(a[j]==0)
                continue;
            else
            {
                swap(a[i], a[j]);
                j++;
            }
        }
        else if(a[j]==0)
            j=i;
    }
    fo(i, j, n)
    {
        if(a[i]==1)
        {
            if(a[j]==1)
                continue;
            else
            {
                swap(a[i], a[j]);
                j++;
            }
        }
        else if(a[j]==1)
            j=i;
    }
    op(a, n);
    return 0;
}
