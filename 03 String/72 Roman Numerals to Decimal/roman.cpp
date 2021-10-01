// Converting Roman Numerals to Decimal
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int romanToDecimal(string &str)
{
    if (str.size() == 0)
        return 0;
    map<char, int> roman;
    roman.insert(make_pair('I', 1));
    roman.insert(make_pair('V', 5));
    roman.insert(make_pair('X', 10));
    roman.insert(make_pair('L', 50));
    roman.insert(make_pair('C', 100));
    roman.insert(make_pair('D', 500));
    roman.insert(make_pair('M', 1000));
    int n = str.size();
    int decimal = roman[str[n - 1]];
    for (int i = n - 2; i >= 0; i--)
    {
        if (roman[str[i]] >= roman[str[i + 1]])
            decimal += roman[str[i]];
        else
            decimal -= roman[str[i]];
    }
    return decimal;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;        
        cout  << romanToDecimal(s) << "\n";
    } 
    return 0;
}