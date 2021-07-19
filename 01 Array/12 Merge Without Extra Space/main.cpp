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
    cout << a[ending] << " ";
}

void merge1(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    while(i<n)
    {
        if(arr1[i]>arr2[j])
        {
            swap(arr1[i], arr2[j]);
            while(j+1<m && arr2[j]>arr2[j+1])
            {
                swap(arr2[j], arr2[j+1]);
                j++;
            }
            j=0;
        }
        i++;
    }
}

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = n-1, j = 0;
    while(0<=i && j<m)
    {
        if(arr1[i]>arr2[j])
            swap(arr1[i], arr2[j]);
        i--;
        j++;
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int arr1[n], arr2[m];
        ip(arr1, n);
        ip(arr2, m);
        merge(arr1, arr2, n, m);
        op(arr1, n);
        op(arr2, m);
        cout << "\n";
    }
    return 0;
}
