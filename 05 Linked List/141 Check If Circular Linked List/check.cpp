bool isCircular(Node *head)
{
   // Your code here
   bool status = false;
   Node* temp = head;
   while(temp->next != NULL)
   {
       if(temp->next == head)
       {
           status = true;
           break;
       }
       temp = temp->next;
   }
   return status;
}