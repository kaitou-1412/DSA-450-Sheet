#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

bool solve(int *a, int n, int mid, int m)
{
    int sum = 0;
    int stu = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
            return false;
        if (sum + a[i] > mid)
        {
            stu++;
            sum = a[i];
            if (stu > m)
                return false;
        }
        else
            sum += a[i];
    }
    return true;
}
int findPages(int arr[], int n, int m)
{
    //code here
    if (n < m)
        return -1;
    //sort(arr, arr+n);
    int lb = 0;
    int s = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];
    int ub = s;
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (solve(arr, n, mid, m))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
            lb = mid + 1;
    }
    return ans;
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
