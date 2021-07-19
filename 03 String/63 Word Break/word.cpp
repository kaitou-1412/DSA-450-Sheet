#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int dictionaryContains(string word, vector<string> &dictionary)
{
    // string dictionary[] = {"mobile", "samsung", "sam", "sung", "man", "mango",
    //                        "icecream", "and", "go", "i", "like", "ice", "cream"};
    // int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < dictionary.size(); i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

bool solve(string str, vector<string> &B)
{
    int size = str.size();
    if (size == 0)
        return true;
    bool wb[size + 1];
    memset(wb, 0, sizeof(wb));
    for (int i = 1; i <= size; i++)
    {
        if (wb[i] == false && dictionaryContains(str.substr(0, i), B))
            wb[i] = true;
        if (wb[i] == true)
        {
            if (i == size)
                return true;
            for (int j = i + 1; j <= size; j++)
            {
                if (wb[j] == false && dictionaryContains(str.substr(i, j - i), B))
                    wb[j] = true;
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;
}

int wordBreak(string A, vector<string> &B)
{
    //code here
    if(solve(A, B)) return 1;
    return 0;
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
        vector<string> b;
        string a = "";
        for(int i=0; i<n; i++)
        {
            cin >> a;
            b.push_back(a);
            a = "";
        }
        cin >> a;
        cout << wordBreak(a, b) << "\n";
    }
    return 0;
}