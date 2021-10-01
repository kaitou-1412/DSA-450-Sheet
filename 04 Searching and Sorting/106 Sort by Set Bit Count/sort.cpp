#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

static bool comp(int a, int b)
{
    return __builtin_popcount(a) > __builtin_popcount(b);
}
void sortBySetBitCount(int arr[], int n)
{
    // Your code goes here
    stable_sort(arr, arr + n, comp);
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        cout << "\n";
    }
    return 0;
}
