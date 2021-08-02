int setBits(int n)
{
    // Write Your Code here
    int res = 0;
    int len = ceil((float)log2(n));
    for (int i = 0; i <= len; i++)
    {
        int x = 1 << i;
        if (n & x)
            res++;
    }
    return res;
}