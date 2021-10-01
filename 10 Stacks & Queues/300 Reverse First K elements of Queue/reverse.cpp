//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    int count = 0;
    stack<int> s;
    while (!q.empty() && count != k)
    {
        s.push(q.front());
        q.pop();
        count++;
    }
    queue<int> ans;
    while (!s.empty())
    {
        ans.push(s.top());
        s.pop();
    }
    while (!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }
    return ans;
}