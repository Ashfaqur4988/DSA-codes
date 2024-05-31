#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node *intersection(Node *head1, Node *head2)
{
    // if any one is empty
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
        {
            return t1;
        }

        if (t1 == NULL)
        {
            t1 = head2;
        }
        if (t2 == NULL)
        {
            t2 = head1;
        }
    }
    return t1;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(5);
    Node *node3 = new Node(2);

    Node *head1 = node1;
    Node *head2 = node2;
    Node *head3 = node3;

    insertAtHead(head1, 3);
    insertAtHead(head2, 4);
    insertAtHead(head2, 2);
    insertAtHead(head2, 1);

    insertAtHead(head3, 6);
    insertAtHead(head3, 4);

    return 0;
}