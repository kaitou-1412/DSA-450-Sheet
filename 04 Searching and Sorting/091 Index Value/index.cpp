#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

vector<int> valueEqualToIndex(int arr[], int n)
{
    // code here
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i - 1] == i)
            v.push_back(i);
    }
    return v;
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