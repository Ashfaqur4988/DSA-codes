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

Node *partition(Node *&head, int x)
{
    Node *dummy1 = new Node(-1);
    Node *dummy2 = new Node(-1);
    Node *left = dummy1;
    Node *right = dummy2;
    Node *temp = head;

    while (temp == NULL || temp->next == NULL)
    {
        return head;
    }

    while (temp != NULL)
    {
        if (temp->data < x)
        {
            left->next = temp;
            left = left->next;
        }
        else
        {
            right->next = temp;
            right = right->next;
        }
        temp = temp->next;
    }
    left->next = dummy2->next;
    right->next = NULL;
    head = dummy1->next;
    return head;
}

int main()
{
    Node *node1 = new Node(2);
    Node *head = node1;
    int arr[5] = {5, 2, 3, 4, 1};
    for (int i = 0; i < 5; i++)
    {
        insertAtHead(head, arr[i]);
    }
    print(head);
    Node *newHead = partition(head, 4);
    print(newHead);

    return 0;
}