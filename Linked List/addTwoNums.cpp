#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
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

void insertAtTail(Node *&tail, int d)
{

    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    else
    {
        Node *temp = head;
        int cnt = 1;
        while (cnt < position)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(tail, d);
            return;
        }

        Node *nodeToBeInserted = new Node(d);
        nodeToBeInserted->next = temp->next;
        temp->next = nodeToBeInserted;
    }
}

Node *getSum(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *t2 = head2;
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    int carry = 0;

    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;
        if (t1)
        {
            sum = sum + t1->data;
        }
        if (t2)
        {
            sum = sum + t2->data;
        }
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;

        if (t1)
        {
            t1 = t1->next;
        }
        if (t2)
        {
            t2 = t2->next;
        }
    }

    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummy->next;
}

int main()
{
    Node *node1 = new Node(3);
    Node *head1 = node1;
    Node *tail1 = node1;

    insertAtTail(tail1, 5);
    print(head1);

    Node *node2 = new Node(4);
    Node *head2 = node2;
    Node *tail2 = node2;

    insertAtPosition(head2, tail2, 1, 5);
    insertAtPosition(head2, tail2, 2, 9);
    insertAtTail(tail2, 9);
    print(head2);

    Node *result = getSum(head1, head2);
    print(result);

    return 0;
}