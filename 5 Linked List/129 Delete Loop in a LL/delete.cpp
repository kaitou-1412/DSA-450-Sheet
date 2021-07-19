void removeLoop(Node *head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *tortoise = head;
    Node *hare = head;
    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (hare == tortoise)
            break;
    }
    if (tortoise == head)
    {
        while (hare->next != head)
            hare = hare->next;
        hare->next = NULL;
    }
    if (hare == tortoise)
    {
        tortoise = head;
        while (tortoise->next != hare->next)
        {
            if (tortoise == hare->next)
                hare->next = NULL;
            tortoise = tortoise->next;
            hare = hare->next;
        }
        hare->next = NULL;
    }
}