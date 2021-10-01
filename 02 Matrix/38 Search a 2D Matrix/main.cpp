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

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int low = 0, high = r-1;
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(matrix[low][0] <= target && target < matrix[mid][0])
            high = mid - 1;
        else if(matrix[mid][c-1] < target && target <= matrix[high][c-1])
            low = mid + 1;
        else
            break;
    }
    low = 0; high = c-1;
    int m;
    while(low<=high)
    {
        m = (low+high)/2;
        if(matrix[mid][m] == target)
            return true;
        else if(matrix[mid][m] < target)
            low = m+1;
        else
            high = m-1;
    }
    return false;
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
        int target;
        cin >> target;
        if(searchMatrix(matrix, target)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
