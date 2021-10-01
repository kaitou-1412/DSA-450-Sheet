#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int *findTwoElement(int *arr, int n)
{
    // code here
    int array[2];
    sort(arr, arr + n);
    int repeat, missing, flag = 0;
    for (int i = 1; i <= n; i++)
    {
        flag += i - arr[i - 1];
        if (i != n && arr[i - 1] == arr[i])
            repeat = arr[i];
    }
    flag += repeat;
    array[0] = repeat;
    array[1] = flag;
    int *p;
    p = array;
    return p;
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
