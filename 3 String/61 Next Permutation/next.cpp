//Next Permutation
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

vector<int> nextPermutation(vector<int>& num, int n)
{
    int k = -1;
    int l;

    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] < num[i + 1])
        {
            k = i;
        }
    }
    if (k == -1)
    {
        sort(num.begin(), num.end());
        return num;
    }

    for (int i = k + 1; i < n; i++)
    {
        if (num[i] > num[k])
        {
            l = i;
        }
    }

    int tmp = num[l];
    num[l] = num[k];
    num[k] = tmp;

    reverse(num.begin() + k + 1, num.end());
    return num;
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
        vector<int> v;
        int ele;
        for(int i=0; i<n; i++)
        {
            cin >> ele;
            v.push_back(ele);
        }
            
        vector<int> v2 = nextPermutation(v, n);
        for (int i=0; i<n; i++)
            cout << v2[i] << " ";
        cout << "\n";
    }
    return 0;
}