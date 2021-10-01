bool KPartition(int arr[], bool taken[], int &n, int k, int &part_sum, int psudeo_sum)
{
    //base conditon
    if (part_sum == psudeo_sum)
    {
        k--;
        psudeo_sum = 0;
        if (k <= 0)
            return true;
    }

    if (part_sum < psudeo_sum)
        return false;

    //conditon logic
    for (int i = 0; i < n; i++)
    {
        if (!taken[i])
        {
            taken[i] = true;
            if (KPartition(arr, taken, n, k, part_sum, psudeo_sum + arr[i]))
                return true;
            taken[i] = false; // Backtracking
        }
    }

    return false;
}

bool isKPartitionPossible(int arr[], int n, int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % k == 0)
    {
        int part_sum = sum / k;
        bool taken[n];
        for (int i = 0; i < n; i++)
            taken[i] = false;
        return KPartition(arr, taken, n, k, part_sum, 0);
    }
    else
        return false;
}
// bool isKPartitionPossible(int a[], int n, int k)
// {
//      //Your code here
//      int sum = a[0], maxa = a[0];
//      for(int i=1; i<n; i++)
//      {
//          sum += a[i];
//          maxa = max(maxa, a[i]);
//      }
//      if(sum%k!=0 || maxa>sum/k) return false;
//      return true;
// }