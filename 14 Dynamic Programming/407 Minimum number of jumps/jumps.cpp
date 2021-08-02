int minJumps(int arr[], int n)
{
    // Your code here
    int jumps = 0, currEnd = 0, currFar = 0;
    for (int i = 0; i < n - 1; i++)
    {
        currFar = max(currFar, i + arr[i]);
        if (i == currEnd)
        {
            jumps++;
            currEnd = currFar;
        }
        if (currEnd >= n - 1)
            break;
    }
    if (currEnd < n - 1)
        return -1;
    return jumps;
}