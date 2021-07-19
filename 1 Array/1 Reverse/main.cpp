#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
//while(str.length()==0) getline(cin, str);
//str = "";
using namespace std;
#define lli long long int
#define ull unsigned long long int
#define fo(i, start, end) for(int i=start;i<end;i++)
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

void input_array(int a[], int n)
{
    fo(i, 0, n) cin >> a[i];
}

void reverse_array(int a[], int n)
{
    int start = 0, ending = n-1;
    while(start<ending)
    {
        int temp = a[start];
        a[start] = a[ending];
        a[ending] = temp;
        start++;
        ending--;
    }
}

void print_array(int a[], int n)
{
    int start = 0, ending = n-1;
    fo(i, start, ending) cout << a[i] << " ";
    cout << a[ending] << "\n";
}

int main()
{
    boost;
    int n;
    cin >> n;
    int a[n];
    input_array(a, n);
    reverse_array(a, n);
    print_array(a, n);
    return 0;
}
