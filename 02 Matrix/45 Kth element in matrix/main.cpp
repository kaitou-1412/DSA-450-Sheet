#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//while(str.length()==0) getline(cin, str);
//str = "";
using namespace std;
#define MAX 1000
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

int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
    int start = matrix[0][0];
    int end = matrix[n-1][n-1];
    while(start<end)
    {
        int j, counter=0;
        int mid = start + (end-start)/2;
        for(int row=0; row<n; row++)
        {
            j = n-1;
            while(j>=0 && matrix[row][j]>mid) j--;
            counter += j+1;
        }
        if(counter<k)
            start = mid+1;
        else
            end = mid;
    }
    return start;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int matrix[MAX][MAX];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                cin >> matrix[i][j];
        cout << kthSmallest(matrix, n, k) << "\n";
    }
    return 0;
}
