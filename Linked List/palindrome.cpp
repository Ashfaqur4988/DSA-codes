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

Node *reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (curr != nullptr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    // find middle
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *newHead = reverse(slow->next);

    Node *i = head;
    Node *j = newHead;

    while (j != NULL)
    {
        if (i->data != j->data)
        {
            reverse(newHead);
            return false;
        }
        i = i->next;
        j = j->next;
    }
    reverse(newHead);
    return true;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    int arr[5] = {2, 3, 3, 2, 1};
    for (int i = 0; i < 5; i++)
    {
        insertAtHead(head, arr[i]);
    }
    print(head);
    bool ans = isPalindrome(head);
    cout << ans << endl;
    return 0;
}