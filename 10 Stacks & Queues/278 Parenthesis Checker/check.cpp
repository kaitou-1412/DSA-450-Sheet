//Function to check if brackets are balanced or not.
bool ispar(string x)
{
    // Your code here
    stack<char> s;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '{')
            s.push('}');
        else if (x[i] == '(')
            s.push(')');
        else if (x[i] == '[')
            s.push(']');
        else if (s.empty())
            return false;
        else if (x[i] == s.top())
            s.pop();
        else
            return false;
    }
    return s.empty();
}