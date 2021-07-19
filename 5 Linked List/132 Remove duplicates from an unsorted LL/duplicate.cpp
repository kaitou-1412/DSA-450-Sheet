Node *removeDuplicates(Node *head)
{
    Node *curr = head->next, *prev = head;
    if (curr == NULL)
        return head;
    unordered_map<int, int> mp;
    while (prev->next != NULL)
    {
        mp[prev->data] = 1;
        if (mp[curr->data] == 1)
        {
            curr = curr->next;
            prev->next = curr;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}