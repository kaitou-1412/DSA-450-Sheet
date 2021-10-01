//Function to get the maximum total value in the knapsack.
static bool compare(Item a, Item b)
{
    return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight);
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, compare);
    double max_profit = 0;
    int curr_weight = 0;
    for (int i = 0; i < n; i++)
    {

        if (curr_weight + arr[i].weight < W)
        {
            max_profit += arr[i].value;
            curr_weight += arr[i].weight;
        }
        else
        {
            max_profit += (W - curr_weight) * arr[i].value * 1.0 / arr[i].weight;
            curr_weight = W;
            break;
        }
    }
    return max_profit;
}