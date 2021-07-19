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

int median(vector<vector<int>> &A, int r, int c)
{
    int min = INT_MAX;
    int max = INT_MIN;
    int desired_count = (1+(r*c))/2;
    for(int i=0;i<r;i++)
    {
        if(A[i][0]<min)
        min = A[i][0];
        if(A[i][c-1]>max)
        max = A[i][c-1];
    }
    int counter =0;
    while(min<max)
    {
        counter=0;
        int mid = (max+min)/2;
        for(int i= 0;i<r;i++)
        {
            counter += upper_bound(A[i].begin(), A[i].end(), mid) -  A[i].begin();
        }
        if(counter < desired_count)
            min = mid+1;
        else
            max = mid;
    }
    return min;
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
        cout << median(matrix, r, c) << "\n";
    }
    return 0;
}
