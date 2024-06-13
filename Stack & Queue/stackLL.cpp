#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int size;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    void push(int element)
    {
        Node *newNode = new Node(element);
        newNode->next = top;
        top = newNode;
        cout << "element pushed" << endl;
        size++;
    }
    int pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        int topData = top->data;
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        size--;
        cout << topData << " popped" << endl;
        return topData;
    }

    int peek()
    {
        if (top == NULL)
        {
            return -1;
        }
        cout << top->data << endl;
        return top->data;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void printStack()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack st;
    st.push(3);
    st.push(1);
    st.push(6);
    st.push(5);
    st.printStack();
    st.pop();
    st.peek();
    if (st.isEmpty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
    st.printStack();

    return 0;
}