#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for " << data << endl;
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

int getLen(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    else
    {
        Node *temp = head;

        int cnt = 1;
        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(head, tail, d);
            return;
        }
        Node *nodeToInsert = new Node(d);

        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        nodeToInsert->prev = temp;
        temp->next = nodeToInsert;
    }
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *current = head;
        Node *previous = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            previous = current;
            current = current->next;
            cnt++;
        }

        if (current->next == NULL)
        {
            tail = previous;
        }
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;

        delete current;
    }
}

int main()
{
    Node *node = new Node(10);
    Node *head = node;
    Node *tail = node;
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtPosition(head, tail, 2, 33);
    print(head);
    deleteAtPosition(head, tail, 4);
    print(head);
    int len = getLen(head);
    cout << "Length " << len << endl;
    cout << "head ->" << head->data << endl;
    cout << "tail ->" << tail->data << endl;

    return 0;
}