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

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> vec;
    while (i < n1 && j < n2 && k < n3)
    {

        if (A[i] == B[j] && B[j] == C[k])
        {
            if(!binary_search(vec.begin(), vec.end(), A[i]))
                vec.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else
            k++;
    }
    return vec;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        int n1, n2, n3;
        cin >> n1;
        int a[n1];
        ip(a, n1);
        cin >> n2;
        int b[n2];
        ip(b, n2);
        cin >> n3;
        int c[n3];
        ip(c, n3);
        vi v = commonElements(a, b, c, n1, n2, n3);
        for(int i = 0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }
    return 0;
}
