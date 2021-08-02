vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    vector<int> v(2);
    int XOR = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        XOR ^= nums[i];
    }
    int mask = XOR & (-XOR);
    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & mask) > 0)
            x ^= nums[i];
    }
    y = XOR ^ x;
    v[0] = min(x, y);
    v[1] = max(x, y);
    return v;
}