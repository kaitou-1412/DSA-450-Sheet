ListNode* middleNode(ListNode* head) 
{
    int n = 1;
    ListNode* temp = head;
    while(temp->next!=NULL) 
    {
        n++;
        temp = temp->next;
    }
    n /= 2;
    temp = head;
    while(n>0)
    {
        temp = temp->next;
        n--;
    }
    return temp;        
}