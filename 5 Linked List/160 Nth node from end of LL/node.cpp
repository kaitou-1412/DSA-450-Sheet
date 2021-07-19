int getNthFromLast(struct Node *head, int n)
{
    struct Node *temp = head;
    int l = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        l++;
    }
    int c = l - n;
    if (c < 0)
        return -1;
    temp = head;
    while (c > 0)
    {
        temp = temp->next;
        c--;
    }
    return temp->data;
}