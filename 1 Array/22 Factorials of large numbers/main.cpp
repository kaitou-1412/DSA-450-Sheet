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
        int n;
        cin >> n;
        int number[10000] = {0};
        number[0] = 1;
        int c = 0, end = 0;
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<=end; j++)
            {
                int m = number[j]*i + c;
                number[j] = m%10;
                c = m/10;
            }
            while(c)
            {
                number[++end] = c%10;
                c = c/10;
            }
        }
        for(int i=end; i>=0; i--)
            cout << number[i];
        cout << "\n";
    }
    return 0;
}
