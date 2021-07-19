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

// Function to find maximum profit earned from at most two stock transactions
int findMaxProfit(int price[], int n)
{
    // create an auxiliary array of size n
    int profit[n];

    // initialize last element of the auxiliary array to 0
    profit[n-1] = 0;

    // to keep track of maximum stock price on the right of current stock price
    int max_so_far = price[n - 1];

    // traverse the array from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        // update profit[i] to the maximum profit earned by a single stock
        // transaction from day i to day n-1
        profit[i] = max(profit[i + 1], max_so_far - price[i]);

        // update maximum stock price seen so far
        max_so_far = max(max_so_far, price[i]);
    }

    // to keep track of minimum stock price to the left of current stock price
    int min_so_far = price[0];

    // traverse the array from left to right
    for (int i = 1; i < n; i++)
    {
        // update profit[i] by taking the maximum of:
        // 1. profit[i-1] which represents the maximum profit calculated so far
        // 2. total profit obtained by closing the first transaction on day i
        // and performing another transaction from day i to day n-1.

        profit[i] = max(profit[i - 1], (price[i] - min_so_far) + profit[i]);

        // update minimum stock price seen so far
        min_so_far = min(min_so_far, price[i]);
    }

    // the last element of profit[] stores the result
    return profit[n - 1];
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
        int price[n];
        ip(price, n);
        cout << "The maximum profit is " << findMaxProfit(price, n) << "\n";
    }
    return 0;
}
