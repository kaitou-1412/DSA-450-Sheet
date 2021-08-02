// Kadane's Algorithm
// Function to find the sum of contiguous subarray with maximum sum.
int maxSubarraySum(int arr[], int n)
{
    // Your code here
    int overall_best = arr[0];
    int curr_best = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr_best = max(arr[i], curr_best + arr[i]);
        overall_best = max(overall_best, curr_best);
    }
    return overall_best;
}