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

struct Pair
{
    int min, max;
};

void ip(int a[], int n)
{
    int i;
    fo(i, 0, n) cin >> a[i];
}

struct Pair getminmax(int a[], int n)
{
    struct Pair minmax;
    if(n%2)
    {
        minmax.min = a[0];
        minmax.max = a[0];
    }
    else
    {
        if(a[0]<a[1])
        {
            minmax.min = a[0];
            minmax.max = a[1];
        }
        else
        {
            minmax.min = a[1];
            minmax.max = a[0];
        }
    }
    int i = 1;
    while(i<n-1)
    {
        if(a[i]<a[i+1])
        {
            if(minmax.max<a[i+1])
                minmax.max = a[i+1];
            if(a[i]<minmax.min)
                minmax.min = a[i];
        }
        else
        {
            if(minmax.max<a[i])
                minmax.max = a[i];
            if(a[i+1]<minmax.min)
                minmax.min = a[i+1];
        }
        i += 2;
    }
    return minmax;
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
    int n;
    cin >> n;
    int a[n];
    ip(a, n);
    struct Pair minmax = getminmax(a, n);
    cout << "Min: " << minmax.min << " Max: " << minmax.max << "\n";
    return 0;
}
