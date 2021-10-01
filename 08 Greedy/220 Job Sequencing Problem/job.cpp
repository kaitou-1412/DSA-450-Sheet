//Function to find the maximum profit and the number of jobs done.
static bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    int day = 0;
    int profit = 0;
    sort(arr, arr + n, compare);
    bool done[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead - 1); j >= 0; j--)
        {
            if (done[j] == false)
            {
                day++;
                profit += arr[i].profit;
                done[j] = true;
                break;
            }
        }
    }
    vector<int> ans = {day, profit};
    return ans;
}