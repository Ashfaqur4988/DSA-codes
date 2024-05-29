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

Node *returnKthToLast(Node *&head, int k)
{
    Node *p1 = head;
    Node *p2 = head;

    for (int i = 0; i < k; i++)
    {
        if (p1 == nullptr)
        {
            return NULL;
        }
        p1 = p1->next;
    }

    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main()
{
    Node *node1 = new Node(8);
    Node *head = node1;
    for (int i = 7; i > 0; i--)
    {
        insertAtHead(head, i);
    }
    print(head);
    Node *result = returnKthToLast(head, 4);
    cout << result->data << endl;
    return 0;
}