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

// reverse kth group
Node *reverseLL(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

Node *getKthNode(Node *temp, int k)
{
    k = k - 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prevLast = NULL;
    while (temp != NULL)
    {
        Node *kthNode = getKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevLast)
            {
                prevLast->next = temp;
            }
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

Node *kReverse2(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    Node *next = nullptr;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // recursion
    if (next != NULL)
    {
        head->next = kReverse2(next, k);
    }

    return prev;
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
    Node *newHead = kReverse2(head, 3);
    print(newHead);
    return 0;
}