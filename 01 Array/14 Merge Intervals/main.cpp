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

bool compareInterval(vector<int> i1, vector<int> i2)
{
    return (i1[0] < i2[0]);
}

vector<int> makeInterval(int intervalStart, int intervalEnd)
{
    vector<int> interval(2);
    interval[0] = intervalStart;
    interval[1] = intervalEnd;
    return interval;
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;
    if(intervals.empty()) return ans;
    sort(intervals.begin(), intervals.end());
    int intervalStart = intervals[0][0], intervalEnd = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++) {
        if(intervalStart <= intervals[i][0] && intervals[i][0] <= intervalEnd) {
            intervalEnd = max(intervalEnd, intervals[i][1]);
        }
        else{
            ans.push_back(makeInterval(intervalStart, intervalEnd));
            intervalStart = intervals[i][0];
            intervalEnd = intervals[i][1];
        }
    }
    ans.push_back(makeInterval(intervalStart, intervalEnd));
    return ans;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v;
        for(int i = 0; i<n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x,y});
        }
        v = merge(v);
        cout << "[";
        for(int i = 0; i<n; i++)
        {
            cout << "[" << v[i][0] << ", " << v[i][1] << "]";
            if(i+1==n)
                break;
            cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
