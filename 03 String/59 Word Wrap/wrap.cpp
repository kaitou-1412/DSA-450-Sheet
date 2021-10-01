//Word Wrap
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

void printp(int p[], int n) //Backtracking
{
    if(p[n] == 1) cout << p[n] << " " << n << " ";
    else
    {
        printp(p, p[n]-1);
        cout << p[n] << " " << n << " "; 
    }
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        int a[n+1];
        for(int i = 1; i<=n; i++)
            cin >> a[i];
        cin >> m;
        int space[n+1][n+1];    //Extra Space for each line
        int ls[n+1][n+1];       //Cost for each line       
        int c[n+1];             //Optimal Cost per line
        int p[n+1];             //Optimal Path
        for(int i=1; i<=n; i++)
        {
            space[i][i] = m - a[i];
            for(int j=i+1; j<=n; j++)
            {
                space[i][j] = space[i][j-1] - a[j] - 1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                if(space[i][j]<0) ls[i][j] = INT_MAX;
                else if(j==n && space[i][j]>=0) ls[i][j] = 0;
                else ls[i][j] = space[i][j]*space[i][j];
            }
        }
        c[0] = 0;
        for(int i=1; i<=n; i++)
        {
            c[i] = INT_MAX;
            for(int j=1; j<=i; j++)
            {
                if(c[j-1]!=INT_MAX && ls[j][i]!=INT_MAX && c[j-1]+ls[j][i]<c[i])
                {
                    c[i] = c[j-1] + ls[j][i];
                    p[i] = j;
                }
            }
        }
        printp(p, n);
        cout << "\n";
    }
    return 0;
}