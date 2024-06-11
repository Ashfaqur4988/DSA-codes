#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int num)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = num;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st(5);
    st.push(2);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    if (st.isEmpty())
    {
        cout << "stack is empty";
    }
    else
    {
        cout << "stack is not empty";
    }

    return 0;
}