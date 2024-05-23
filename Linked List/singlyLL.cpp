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

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "freeing memory from " << data << " " << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    // new node create
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

void insertInPosition(Node *&tail, Node *&head, int position, int d)
{
    // insertion in first position
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    // getting the head for the traversal
    Node *temp = head;
    int cnt = 1;
    // traversing to the position
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // insertion in last node
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating the node to be inserted
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    // if first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    else
    {
        // any other node
        Node *current = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = current;
            current = current->next;
            cnt++;
        }

        // handling last node
        if (current->next == NULL)
        {
            tail = prev;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

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

int main()
{
    // creation
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(head, 12);
    insertAtTail(tail, 20);
    insertInPosition(tail, head, 3, 50);

    print(head);
    deleteNode(4, head, tail);
    print(head);
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    return 0;
}