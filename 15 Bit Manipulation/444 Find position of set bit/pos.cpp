int findPosition(int n)
{
    // code here
    if (n == 0)
        return -1;
    int x = log2(n);
    int y = ceil(log2(n));
    if (x != y)
        return -1;
    return (x + 1);
}