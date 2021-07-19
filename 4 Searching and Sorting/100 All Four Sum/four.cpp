#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

vector<vector<int>> fourSum(vector<int> &num, int target)
{
    // Your code goes here
    vector<vector<int>> res;
    if (num.empty())
        return res;
    int n = num.size();
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target2 = target - num[j] - num[i];
            int front = j + 1;
            int back = n - 1;
            while (front < back)
            {
                int two_sum = num[front] + num[back];
                if (two_sum < target2)
                    front++;
                else if (two_sum > target2)
                    back--;
                else
                {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[front];
                    quadruplet[3] = num[back];
                    res.push_back(quadruplet);
                    while (front < back && num[front] == quadruplet[2])
                        front++;
                    while (front < back && num[back] == quadruplet[3])
                        back--;
                }
            }
            while (j + 1 < n && num[j + 1] == num[j])
                j++;
        }
        while (i + 1 < n && num[i + 1] == num[i])
            i++;
    }
    return res;
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
