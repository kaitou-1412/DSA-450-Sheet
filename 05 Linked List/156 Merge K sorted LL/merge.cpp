Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *result = NULL;
    if (a->data < b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}
//Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    int i = 0;
    int last = K - 1;
    int j;
    while (last != 0)
    {
        i = 0;
        j = last;
        while (i < j)
        {
            arr[i] = merge(arr[i], arr[j]);
            i++;
            j--;
            if (i >= j)
                last = j;
        }
    }
    return arr[0];
}