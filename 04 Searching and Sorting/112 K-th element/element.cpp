#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int i = n - 1, j = 0;
    while (0 <= i && j < m)
    {
        if (arr1[i] > arr2[j])
            swap(arr1[i], arr2[j]);
        i--;
        j++;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    if (k <= n)
        return arr1[k - 1];
    return arr2[k - n - 1];
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
