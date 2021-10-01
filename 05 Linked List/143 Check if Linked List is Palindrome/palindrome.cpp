bool isPalindrome(Node *head)
{
    //Your code here
    Node *slow = head, *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node *prev = NULL, *next, *curr = slow;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    fast = head;
    while(prev!=NULL)
    {
        if(fast->data != prev->data) return false;
        fast = fast->next;
        prev = prev->next;
    }
    return true;
}