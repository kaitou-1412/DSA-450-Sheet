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

void nextPermutation(vector<int>& num)
{
    int n = num.size();
    int k=-1;
    int l;

    for (int i=0;i<n-1;i++){
        if (num[i]<num[i+1]){
            k=i;
        }
    }
    if (k==-1){
        sort(num.begin(),num.end());
        return;
    }

    for (int i=k+1;i<n;i++){
        if (num[k]<num[i]){
            l=i;
        }
    }

    int tmp = num[l];
    num[l]=num[k];
    num[k]=tmp;

    reverse(num.begin()+k+1,num.end());
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
        int a[n];
        ip(a, n);
        vi v(a, a+n);
        nextPermutation(v);
        for(int i = 0; i<n; i++)
            cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}


