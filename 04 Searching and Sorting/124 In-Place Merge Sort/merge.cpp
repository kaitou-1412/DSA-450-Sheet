#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define lli long long int
//while(str.length()==0) getline(cin, str);
//str = "";

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return ((gap+1)/2);
}

void swap(int *nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void inPlaceMerge(int *nums, int start, int end)
{
    int gap = end - start + 1;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (int i = start; i + gap <= end; i++)
        {
            int j = i + gap;
            if (nums[i] > nums[j])
                swap(nums, i, j);
        }
    }
}

void mergeSort(int *nums, int s, int e)
{
    if (s == e)
        return;

    // Calculating mid to slice the
    // array in two halves
    int mid = (s + e) / 2;
    // Recursive calls to sort left
    // and right subarrays
    mergeSort(nums, s, mid);
    mergeSort(nums, mid + 1, e);
    inPlaceMerge(nums, s, e);
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    boost;
    int nums[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    mergeSort(nums, 0, n - 1);
    printArray(nums, n);
    return 0;
}
