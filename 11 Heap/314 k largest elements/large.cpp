vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> res;
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}