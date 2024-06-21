#include <bits/stdc++.h>
// Implement class for minStack.
class minStack
{
    // Write your code here.
    stack<int> st, min_stack;

public:
    // Constructor
    minStack()
    {
        // Write your code here.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        // Write your code here.
        if (min_stack.empty() || num <= min_stack.top())
        {
            min_stack.push(num);
        }
        st.push(num);
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (!st.empty())
        {
            int num = st.top();
            if (st.top() == min_stack.top())
            {
                min_stack.pop();
            }
            st.pop();
            return num;
        }
        else
        {
            return -1;
        }
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        // Write your code here.
        return st.top();
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        // Write your code here.
        if (!min_stack.empty())
        {
            return min_stack.top();
        }

        return -1;
    }
};