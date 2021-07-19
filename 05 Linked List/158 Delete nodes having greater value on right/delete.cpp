Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *compute(Node *head)
{
    // your code goes here
    head = reverse(head);
    Node *curr = head;
    int ma = head->data;
    Node *prev = head;
    head = head->next;
    while (head)
    {
        if (head->data >= ma)
        {
            ma = head->data;
            prev = head;
            head = head->next;
        }
        else
        {
            prev->next = head->next;
            head = prev->next;
        }
    }
    head = reverse(curr);
    return head;
}