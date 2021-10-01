int minValue(string s, int k)
{
    // code here
    unordered_map<char, int> mp;
    priority_queue<int> pq;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for (int i = 97; i < 123; i++)
    {
        char ch = char(i);
        if (mp[ch])
            pq.push(mp[ch]);
    }
    int maxy;
    while (k > 0)
    {
        maxy = pq.top();
        pq.pop();
        maxy--;
        k--;
        if (maxy > 0)
            pq.push(maxy);
    }
    int sum = 0, ele;
    while (!pq.empty())
    {
        ele = pq.top();
        sum += ele * ele;
        pq.pop();
    }
    return sum;
}