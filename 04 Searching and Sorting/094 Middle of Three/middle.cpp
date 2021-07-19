#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int middle(int A, int B, int C)
{
    //code here//Position this line where user code will be pasted.
    if ((A < B && B < C) || (C < B && B < A))
        return B;
    else if ((B < C && C < A) || (A < C && C < B))
        return C;
    return A;
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