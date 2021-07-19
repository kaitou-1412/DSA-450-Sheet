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

void ip(lli a[], lli n)
{
    lli i;
    fo(i, 0, n) cin >> a[i];
}

void op(int a[], int n)
{
    int i, start = 0, ending = n-1;
    fo(i, start, ending) cout << a[i] << " ";
    cout << a[ending] << "\n";
}

long long countMerge(long long A[], long long l, long long mid, long long h)
{
    long long n1 = mid - l + 1;
    long long n2 = h - mid;
    long long int res = 0;
    long long left[n1];
    long long right[n2];
    long long i ,j, k = l;
    for(i = 0 ; i < n1 ; i++)
        left[i] = A[l+i];

    for(j = 0 ; j < n2 ; j++)
        right[j] = A[mid+j+1];

    i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
            A[k++] = left[i++];
        else
        {
            A[k++] = right[j++];
            res += n1-i;
        }
    }
    while(i < n1) A[k++] = left[i++];
    while(j < n2) A[k++] = right[j++];
    return res;
}

long long int countInversion(long long A[],long long l, long long h)
{
    long long int res = 0;
    if(l < h)
    {
        int mid = l+(h-l)/2;
        res += countInversion(A,l,mid);
        res += countInversion(A,mid+1,h);
        res += countMerge(A,l,mid,h);
    }
    return res;
}

long long int inversionCount(long long A[],long long N)
{
    long long int res = countInversion(A,0,N-1);
    return res;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long int a[n];
        ip(a, n);
        cout << inversionCount(a, n) << "\n";
    }
    return 0;
}
