int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{
    // Your code goes here
    int sum = 0;
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] - arr[i + 1] < k)
        {
            sum += arr[i] + arr[i + 1];
            i++;
        }
    }
    return sum;
}