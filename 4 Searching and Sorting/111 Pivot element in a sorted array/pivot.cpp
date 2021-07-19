#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

// A Divide-and-Conquer approach to find the pivot (highest) element in
// a sorted rotated array - returns the index of the pivot -> O(log N)
int peakElement(int arr[], int low, int high, int lowerBound, int upperBound)
{
    int mid = low + (high - low) / 2;

    if (mid == lowerBound)
    {
        if (mid == upperBound)
        {
            // Only 1 element
            return mid;
        }
        else if (arr[mid] >= arr[mid + 1])
        {
            // Pivot is the greater element
            return mid;
        }
    }
    else if (mid == upperBound)
    {
        if (arr[mid] >= arr[mid - 1])
        {
            // Pivot is the greater element
            return mid;
        }
    }
    else
    {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
        {
            // Mid value is the pivot
            return mid;
        }
        else if (arr[mid] > arr[high])
        {
            // The Pivot is in the second half
            return peakElement(arr, mid + 1, high, lowerBound, upperBound);
        }
        else if (arr[mid] < arr[high])
        {
            // The Pivot is in the first half
            return peakElement(arr, low, mid - 1, lowerBound, upperBound);
        }
    }

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
