/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &s, int x)
{
    stack<int> temp;
    while (!s.empty() && s.top() > x)
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(x);
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}
void SortedStack ::sort()
{

    if (!s.empty())
    {
        int x;
        x = s.top();
        s.pop();
        SortedStack::sort();
        insert(s, x);
    }
}