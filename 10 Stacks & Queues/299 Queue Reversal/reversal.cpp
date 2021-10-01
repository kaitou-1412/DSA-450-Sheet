//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // add code here.
    stack<long long int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}