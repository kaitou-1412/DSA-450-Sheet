#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int minSwaps(vector<int> &arr)
{
    // Code here
    int N = arr.size();
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
        v[i] = {arr[i], i};
    sort(v.begin(), v.end());
    int c = 0;
    for (int i = 0; i < N; i++)
    {

        if (v[i].second == i)
            continue;
        else
        {
            c++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return c;
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
