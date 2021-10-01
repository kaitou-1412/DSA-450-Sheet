// Using Quick Select Algorithm 
// Time Complexity:
// Average Case: O(N)
// Best Case: O(N)
// Worst Case: O(N^2)
#include <bits/stdc++.h>
#define fo(i, start, ending) for(i=start;i<ending;i++)
using namespace std;

int partition(int arr[], int l, int r)
{
	int x = arr[r], j = l;
	for (int i = l; i <= r - 1; i++)
    {
		if (arr[i] <= x)
		{
			swap(arr[i], arr[j]);
			j++;
		}
	}
	swap(arr[j], arr[r]);
	return j;
}

int kthSmallest(int arr[], int l, int r, int k)
{
	if (0<k && k<=r-l+1)
    {
		int index = partition(arr, l, r);
		if (k == index-l+1)
			return arr[index];
		if (k < index-l+1)
			return kthSmallest(arr, l, index - 1, k);
		return kthSmallest(arr, index + 1, r, k - (index - l + 1));
	}
	return INT_MAX;
}

void ip(int a[], int n)
{
    int i;
    fo(i, 0, n) cin >> a[i];
}

int main()
{
    int n;
    cin >> n;
	int a[n];
	ip(a, n);
	int k;
	cin >> k;
	cout << "Kth Smallest: " << kthSmallest(a, 0, n-1, k)
        << "\nKth Largest: " << kthSmallest(a, 0, n-1, n-k+1);
	return 0;
}
