#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int search(vector<int> &nums, int target)
{
    vector<int>::iterator it;
    it = find(nums.begin(), nums.end(), target);
    if (it == nums.end())
        return -1;
    return (it - nums.begin());
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
