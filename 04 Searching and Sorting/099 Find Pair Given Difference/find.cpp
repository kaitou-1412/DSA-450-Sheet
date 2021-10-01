#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, num, ele;
        cin >> n >> num;
        int arr[n];
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m[arr[i]] = 1;
        }
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (m[arr[i] + num] == 1 || m[arr[i] - num] == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "1\n";
        else
            cout << "-1\n";
    }
    return 0;
}
