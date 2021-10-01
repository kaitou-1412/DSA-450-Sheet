long long findMinDiff(vector<long long> a, long long n, long long m)
{
    //code
    sort(a.begin(), a.end());
    long long int mi = INT_MAX;
    for (int i = 0; i <= n - m; i++)
        mi = min(mi, a[i + m - 1] - a[i]);
    return mi;
}