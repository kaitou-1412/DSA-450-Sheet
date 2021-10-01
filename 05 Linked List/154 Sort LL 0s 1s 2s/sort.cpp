Node *segregate(Node *head)
{

    // Add code here
    int cnt[3] = {};
    for (Node *i = head; i != 0; i = i->next)
        cnt[i->data]++;
    Node *x = head;
    for (int i = 0; i < 3; i++)
    {
        while (cnt[i]--)
        {
            x->data = i;
            x = x->next;
        }
    }
    return head;
}