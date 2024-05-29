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
void removeDups(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << "func end" << endl;

        // remove all further nodes having the same value
        Node *front = curr;
        while (front->next != NULL)
        {
            if (front->next->data == curr->data)
            {
                front->next = front->next->next;
            }
            else
            {
                front = front->next;
            }
        }
        curr = curr->next;
    }
    cout << "func end" << endl;
}

int main()
{
    Node *node1 = new Node(8);
    Node *head = node1;
    for (int i = 7; i > 0; i--)
    {
        insertAtHead(head, i);
    }
    insertAtHead(head, 7);
    print(head);
    removeDups(head);
    print(head);

    return 0;
}