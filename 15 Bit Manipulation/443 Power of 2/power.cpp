// Function to check if given number n is a power of two.
bool isPowerofTwo(long long n)
{
    // Your code here
    if (n == 0)
        return false;
    if (log2(n) == ceil(log2(n)))
        return true;
    return false;
}