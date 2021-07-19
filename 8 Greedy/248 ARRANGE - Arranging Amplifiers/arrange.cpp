#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

bool check(int a, int b)
{
    if(a+b == 5 and abs(a-b) == 1)
        return true;
    return false;
}

void print(int a[], int n)
{
    for(int i = 0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
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
        int a[n] = {0};
        int ones = 0;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            if(a[i] == 1) ones++;
        }
        sort(a, a+n, greater<>());
        for (int i = 0; i < ones; i++)
            cout << "1 ";
        if ((n - ones) == 2 and a[0] == 3 and a[1] == 2)
            cout << "2 3" << endl;
        else
        {
            for (int i = 0; i < (n - ones); i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
