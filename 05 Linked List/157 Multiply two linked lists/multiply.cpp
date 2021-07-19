long long multiplyTwoLists(Node *l1, Node *l2)
{
    //Your code here
    long long mod = 1000000007;
    long long n = 0, m = 0;
    while (l1 != NULL)
    {
        n = (n + l1->data) % mod;
        if (l1->next != NULL)
            n = (n * 10) % mod;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        m = (m + l2->data) % mod;
        if (l2->next != NULL)
            m = (m * 10) % mod;
        l2 = l2->next;
    }
    return (((n % mod) * (m % mod)) % mod);
}