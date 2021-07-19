#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

string secFrequent(string arr[], int n)
{
    map<string, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    map<string, int>::iterator it;
    int maxi = 0, maxi2 = 0;
    string sec = "";
    for (it = freq.begin(); it != freq.end(); it++)
        maxi = max(maxi, it->second);
    for (it = freq.begin(); it != freq.end(); it++)
    {
        if (maxi2 < it->second && it->second < maxi)
        {
            maxi2 = it->second;
            sec = it->first;
        }
    }
    return sec;
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
        string arr[n];
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        cout << secFrequent(arr, n) << "\n";
    }
    return 0;
}
