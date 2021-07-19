struct Node* reverseDLL(struct Node * head)
{
    struct Node* prev = NULL, *curr = head, *next;
    while(curr!=NULL)
    {
        next = curr->next;
        prev = curr->prev;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}