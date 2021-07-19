//Permutations of a given string
//print all permutations of a given string S
//with single space and all permutations should
//be in lexicographically increasing order
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

set<string> lex;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
    {
        string s(a);
        lex.insert(s);
        //cout << a << endl;
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}

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
        char str[n + 1];
        strcpy(str, s.c_str());
        permute(str, 0, n - 1);
        set<string>::iterator it;
        for (it = lex.begin(); it != lex.end(); it++)
            cout << *it << " ";
        cout << "\n";
        lex.clear();
    }
    return 0;
}