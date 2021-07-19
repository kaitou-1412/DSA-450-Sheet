int pageFaults(int N, int c, int pages[])
{
    // code here
    list<int> q;
    int page_faults = 0;
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        if (m[pages[i]] != 1)
        {
            page_faults++;
            if (q.size() < c)
            {
                q.push_back(pages[i]);
                m[pages[i]] = 1;
            }
            else if (q.size() == c)
            {
                int ans = q.front();
                q.pop_front();
                q.push_back(pages[i]);
                m[ans] = 0;
                m[pages[i]] = 1;
            }
        }
        else
        {
            auto it = find(q.begin(), q.end(), pages[i]);
            q.erase(it);
            q.push_back(pages[i]);
        }
    }
    return page_faults;
}