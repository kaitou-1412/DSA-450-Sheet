//Using Quick Select Algorithm
#include <bits/stdc++.h>
#define fo(i, start, ending) for(i=start;i<ending;i++)
using namespace std;

int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
    {
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
	if (0<k && k<=r-l+1)
    {
		int index = partition(arr, l, r);
		if (k-1 == index-l)
			return arr[index];
		if (k-1 < index-l)
			return kthSmallest(arr, l, index - 1, k);
		return kthSmallest(arr, index + 1, r,
							k - index + l - 1);
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
