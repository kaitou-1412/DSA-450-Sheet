//Function to push an element in queue by using 2 stacks.
void StackQueue ::push(int x)
{
    // Your Code
    if (!s1.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    else
        s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    // Your Code
    int res = -1;
    if (!s1.empty())
    {
        res = s1.top();
        s1.pop();
    }
    return res;
}