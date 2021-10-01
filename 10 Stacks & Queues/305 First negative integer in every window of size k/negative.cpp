vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k)
{
    long long int i = 0, j = 0;
    vector<long long int> ans;
    deque<long long int> q;
    while (j < n)
    {
        if (a[j] < 0)
            q.push_back(a[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (!q.empty())
                ans.push_back(q.front());
            else
                ans.push_back(0);
            if (a[i] < 0)
                q.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}