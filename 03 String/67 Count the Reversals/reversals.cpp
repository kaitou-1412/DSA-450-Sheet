//Count the Reversals
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
        string s;
        cin >> s;
        int n = s.size();
        if(n%2!=0) cout << "-1\n";
        else
        {
            int c = 0, n1 = 0, n2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '{')
                    n1++;
                else if(s[i] == '}')
                {
                    if (n1 == 0)
                        n2++;
                    else
                        n1--;
                }    
            }
            c += (n1 + (n1 % 2)) / 2 + (n2 + (n2 % 2)) / 2;
            cout << c << "\n";
        }
    }
    return 0;
}