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

// iterative
Node *reverse1(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        cout << "not reversed" << endl;
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    cout << "after reverse iterative: ";
    return prev;
}

// recursive solution
Node *recReverse(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *newHead = recReverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 2);
    print(head);

    insertAtTail(tail, 5);
    print(head);

    insertAtPosition(head, tail, 3, 6);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    head = reverse1(head);
    print(head);

    Node *newRecHead = recReverse(head);
    cout << "recursive reverse: ";
    print(newRecHead);

    return 0;
}