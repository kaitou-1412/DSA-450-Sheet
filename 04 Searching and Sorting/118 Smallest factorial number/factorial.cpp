#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

bool check(int p, int n)
{
    //Check if there are atleast n trailing zeroes in mid(p)
    int temp = p, count = 0, f = 5;
    while (f <= temp)
    {
        count += temp / f;
        f = f * 5;
    }
    return (count >= n);
}
int findNum(int n)
{
    //complete the function here
    if (n == 1)
        return 5;
    int low = 0;
    int high = 5 * n;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (check(mid, n))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
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
