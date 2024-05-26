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

Node *middle(Node *&head)
{
    Node *temp = head;
    if (temp->next == NULL)
    {
        return temp;
    }
    else
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
}

int main()
{
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 1);
    insertAtPosition(head, tail, 2, 3);
    insertAtPosition(head, tail, 3, 5);
    insertAtTail(tail, 4);
    print(head);
    Node *mid = middle(head);
    cout << mid->data << endl;
    return 0;
}