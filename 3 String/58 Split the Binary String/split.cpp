//Split the binary string into substrings with equal number of 0s and 1s
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

// Function to return the count 
// of maximum substrings str 
// can be divided into 
int maxSubStr(string str, int n) 
{ 
  
    // To store the count of 0s and 1s 
    int count0 = 0, count1 = 0; 
  
    // To store the count of maximum 
    // substrings str can be divided into 
    int cnt = 0; 
    for (int i = 0; i < n; i++) { 
        if (str[i] == '0') { 
            count0++; 
        } 
        else { 
            count1++; 
        } 
        if (count0 == count1) { 
            cnt++; 
        } 
    } 
  
    // It is not possible to 
    // split the string 
    if (count0 != count1) { 
        return -1; 
    } 
  
    return cnt; 
}

int main()
{
    boost;
    string str;
    cin >> str;
    //str = "0100110101";
    int n = str.length();
    cout << maxSubStr(str, n);
    return 0;
}