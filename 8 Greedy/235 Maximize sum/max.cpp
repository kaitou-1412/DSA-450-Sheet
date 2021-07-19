int Maximize(int a[], int n)
{
    // Complete the function
    sort(a, a + n);
    long long int sum = 0;
    int m = 1000000007;
    for (int i = 0; i < n; i++)
        sum = ((sum % m) + ((((long long int)a[i] % m) * (i % m)) % m)) % m;
    return (int)sum;
}