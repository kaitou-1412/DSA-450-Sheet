#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    //code here
    long long int p = 1;
    vector<long long int> prod;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            p *= nums[i];
        if (nums[i] == 0)
        {
            flag = true;
            count++;
        }
    }
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (count == 1)
                    prod.push_back(p);
                else
                    prod.push_back(0);
            }
            else
                prod.push_back(0);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
            prod.push_back(p / nums[i]);
    }
    return prod;
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
