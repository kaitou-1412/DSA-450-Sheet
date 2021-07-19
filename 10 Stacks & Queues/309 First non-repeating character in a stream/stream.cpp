string FirstNonRepeating(string A)
{
    // Code here
    string s = "";
    queue<char> q;
    int arr[26] = {0};
    for (int i = 0; i < A.size(); i++)
    {
        q.push(A[i]);
        arr[A[i] - 'a']++;
        while (!q.empty())
        {
            if (arr[q.front() - 'a'] > 1)
                q.pop();
            else
                break;
        }
        if (q.empty())
            s += '#';
        else
            s += q.front();
    }
    return s;
    // vector <int> vis(26, 0);
    // string ans = "";
    // vector <char> v;
    // int n = A.length();
    // for(int i = 0; i<n; i++)
    // {
    //     if(!vis[A[i] - 'a'])
    //         v.push_back(A[i]);
    //     vis[A[i] - 'a']++;
    //     int f = 0;
    //     int m = v.size();
    //     for(int j = 0; j<v.size(); j++)
    //     {
    //         if(vis[v[j] - 'a'] == 1)
    //         {
    //             ans.push_back(v[j]);
    //             f = 1;
    //             break;
    //         }
    //     }
    //     if(f == 0)
    //         ans.push_back('#');
    // }
    // return ans;
}