// you are required to complete this function
// function should print the required range
#include <vector>
#include <queue>
#define type pair<int, pair<int, int>>
pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
    //code here
    priority_queue<type, vector<type>, greater<type>> pq;
    int maxi = -1, range = INT_MAX;
    pair<int, int> res;
    for (int i = 0; i < k; i++)
    {
        pq.push(make_pair(arr[i][0], make_pair(i, 0)));
        maxi = max(maxi, arr[i][0]);
    }
    for (int i = 0; i < n * k; i++)
    {
        int mini = pq.top().first;
        int index = pq.top().second.first;
        int pos = pq.top().second.second;
        if (range > maxi - mini)
        {
            range = maxi - mini;
            res = make_pair(mini, maxi);
        }
        maxi = max(maxi, arr[index][pos + 1]);
        pq.pop();
        if (pos == n - 1)
            break;
        pq.push(make_pair(arr[index][pos + 1], make_pair(index, pos + 1)));
    }
    return res;
}