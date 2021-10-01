#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    long long c = 0;
    sort(arr, arr + n);
    for (int k = 0; k < n - 2; k++)
    {
        int i = k + 1;
        int j = n - 1;
        while (i < j)
        {
            int s = arr[k] + arr[i] + arr[j];
            if (s < sum)
            {
                c += j - i;
                i++;
            }
            else
                j--;
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
