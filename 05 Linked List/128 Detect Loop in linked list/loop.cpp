bool detectLoop(Node *head)
{
    // your code here
    Node *tortoise = head;
    Node *hare = head;
    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (hare == tortoise)
            return true;
    }
    return false;
}