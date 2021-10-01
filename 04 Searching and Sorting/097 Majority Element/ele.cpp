#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int majorityElement(int arr[], int n)
{
    // your code here
    // Number of bits in the integer
    int len = sizeof(int) * 8;

    // Variable to calculate majority element
    int number = 0;

    // Loop to iterate through all the bits of number
    for (int i = 0; i < len; i++)
    {
        int count = 0;
        // Loop to iterate through all elements in array
        // to count the total set bit
        // at position i from right
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
                count++;
        }
        // If the total set bits exceeds n/2,
        // this bit should be present in majority Element.
        if (count > (n / 2))
            number += (1 << i);
    }

    int count = 0;

    // iterate through array get
    // the count of candidate majority element
    for (int i = 0; i < n; i++)
        if (arr[i] == number)
            count++;

    // Verify if the count exceeds n/2
    if (count > (n / 2))
        return number;
    else
        return -1;
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
