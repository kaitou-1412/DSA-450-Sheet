vector<int> candyStore(int candies[], int N, int K)
{
    // Write Your Code here
    int candy = N;
    int min_amount = 0, max_amount = 0;
    sort(candies, candies + N);
    int i = 0;
    while (i < N)
    {
        if (candy <= 0)
            break;
        min_amount += candies[i];
        candy -= K;
        candy--;
        i++;
    }
    i = N - 1;
    candy = N;
    while (i >= 0)
    {
        if (candy <= 0)
            break;
        max_amount += candies[i];
        candy -= K;
        candy--;
        i--;
    }
    return {min_amount, max_amount};
}