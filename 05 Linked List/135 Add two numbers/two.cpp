struct Node *reverse(Node *head)
{
    Node *next = NULL;
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//Function to add two numbers represented by linked list.
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // code here
    first = reverse(first);
    second = reverse(second);
    int c = 0, s = 0;
    Node *temp, *res = NULL, *curr = NULL;
    while (first != NULL || second != NULL)
    {
        s = c + (first ? first->data : 0) + (second ? second->data : 0);
        c = s / 10;
        s = s % 10;
        temp = new Node(s);
        if (res == NULL)
            res = temp;
        else
            curr->next = temp;
        curr = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (c > 0)
    {
        temp = new Node(c);
        curr->next = temp;
        curr = temp;
    }
    res = reverse(res);
    return res;
}