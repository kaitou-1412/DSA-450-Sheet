// Function to find number of bits needed to be flipped to convert A to B
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
int countBitsFlip(int a, int b)
{
    // Your logic here
    int XOR = a ^ b;
    return setBits(XOR);
}