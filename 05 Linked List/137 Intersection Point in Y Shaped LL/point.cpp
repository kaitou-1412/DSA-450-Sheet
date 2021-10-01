int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
            return temp1->data;
        if (temp1->next == NULL)
            temp1 = head2;
        if (temp2->next == NULL)
            temp2 = head1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}