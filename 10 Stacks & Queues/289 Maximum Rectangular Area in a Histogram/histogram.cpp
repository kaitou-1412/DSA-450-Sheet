//https://www.youtube.com/watch?v=lsQTYlCiU6c&t=637s&ab_channel=Knapsak
//Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n)
{
    // Your code here
    stack<int> st;
    long area = 0, max = 0;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || arr[i] >= arr[st.top()])
        {
            st.push(i);
            i++;
        }
        else
        {
            int curr = st.top();
            st.pop();
            area = arr[curr] * (st.empty() ? i : (i - 1 - st.top()));
            if (area > max)
                max = area;
        }
    }
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        area = arr[curr] * (st.empty() ? n : (n - 1 - st.top()));
        if (area > max)
            max = area;
    }
    return max;
}