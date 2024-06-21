void insetAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }

    int x = stack.top();
    stack.pop();

    insetAtBottom(stack, num);
    stack.push(x);
}

void reverseStack(stack<int> &stack)
{
    // Write your code here
    // base case
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insetAtBottom(stack, num);
}