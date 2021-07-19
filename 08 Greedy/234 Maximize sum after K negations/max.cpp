long long int maximizeSum(long long int a[], int n, int k)
{
    // Your code goes here
    sort(a, a + n);
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 and k > 0)
        {
            a[i] = -a[i];
            k--;
        }
    }
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (k & 1)
    {
        long long int x = *min_element(a, a + n);
        sum -= 2 * x;
    }
    return sum;
}