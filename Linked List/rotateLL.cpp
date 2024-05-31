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

Node *findNewNode(Node *head, int n)
{
    int cnt = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (cnt == n)
        {
            return temp;
        }
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node *rotate(Node *head, int k)
{
    if (head == NULL || k == 0)
    {
        return head;
    }
    Node *tail = head;
    int len = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }
    if (k % len == 0)
    {
        return head;
    }

    k = k % len;
    tail->next = head;
    Node *temp = findNewNode(head, len - k);
    head = temp->next;
    temp->next = NULL;

    return head;
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
    Node *newHead = rotate(head, 2);
    print(newHead);
    return 0;
}