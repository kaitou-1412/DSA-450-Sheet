#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

vector<int> find(int arr[], int n, int x)
{
    // code here
    vector<int> v(arr, arr + n);
    vector<int> result;
    vector<int>::iterator lower, upper;
    lower = lower_bound(v.begin(), v.end(), x);
    upper = upper_bound(v.begin(), v.end(), x);
    if (find(v.begin(), v.end(), x) == v.end())
    {
        result.push_back(-1);
        result.push_back(-1);
    }
    else
    {
        result.push_back(lower - v.begin());
        result.push_back(upper - v.begin() - 1);
    }
    return result;
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
