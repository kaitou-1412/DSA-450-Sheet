//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);
    int j = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= dep[j])
            count++;
        else
            j++;
    }
    return count;
}