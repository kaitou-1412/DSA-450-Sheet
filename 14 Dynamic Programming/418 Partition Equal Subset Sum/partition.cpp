// Given an array arr[] of size N, 
// check if it can be partitioned into two parts 
// such that the sum of elements in both parts is the same.

int dp[101][10001];
int subset_sum(int n, int arr[], int tgt)
{
    if (n == 0)
        return 0;
    if (tgt == 0)
        return 1;
    if (dp[n][tgt] != -1)
        return dp[n][tgt];
    if (arr[n - 1] <= tgt)
        return dp[n][tgt] = subset_sum(n - 1, arr, tgt - arr[n - 1]) || subset_sum(n - 1, arr, tgt);
    return dp[n][tgt] = subset_sum(n - 1, arr, tgt);
}
int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    memset(dp, -1, sizeof(dp));
    if (sum % 2 != 0)
        return 0;
    else
        return subset_sum(N, arr, sum / 2);
}