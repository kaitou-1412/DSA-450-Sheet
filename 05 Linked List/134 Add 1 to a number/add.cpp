#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node* node)
{
    while(node != NULL)
    {
        cout << node->data << " ";
        node  = node->next;
    }
    cout << "\n";
}

Node *reverse(Node *head)
{
    Node *next = NULL;
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    head = reverse(head);
    bool f = true;
    Node *curr = head;
    while (curr != NULL && f)
    {
        if (curr->next == NULL && curr->data == 9)
        {
            curr->data = 1;
            Node *temp = new Node(0);
            temp->next = head;
            head = temp;
            curr = curr->next;
        }
        else if (curr->data == 9)
        {
            curr->data = 0;
            curr = curr->next;
        }
        else
        {
            curr->data += 1;
            curr = curr->next;
            f = false;
        }
    }
    head = reverse(head);
    return head;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        cout << "\n";
    }
    return 0;
}