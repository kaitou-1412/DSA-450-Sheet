long long minCost(long long arr[], long long n)
{
    // Your code here
    if (n == 1)
        return 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);
    long long min_cost = 0;
    while (pq.size() > 1)
    {
        long long a = pq.top();
        ;
        pq.pop();
        long long b = pq.top();
        ;
        pq.pop();
        min_cost += a + b;
        pq.push(a + b);
    }
    return min_cost;
}