void removeDuplicates(struct Node *head)
{
    struct Node *prev = head, *curr = head->next;
    if (curr == NULL)
        return;
    while (curr->next != NULL)
    {
        if (prev->data != curr->data)
        {
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }
    if (prev->data == curr->data)
        prev->next = NULL;
    else
        prev->next = curr;
}