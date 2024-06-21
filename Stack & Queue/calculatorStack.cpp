#include <iostream>
#include <stack>
using namespace std;

int calculate(string &post)
{
    stack<int> st;
    for (auto c : post)
    {
        if (c == '/' || c == '*' || c == '+' || c == '-')
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            if (c == '+')
            {
                st.push(op1 + op2);
            }
            if (c == '-')
            {
                st.push(op1 - op2);
            }
            if (c == '*')
            {
                st.push(op1 * op2);
            }
            if (c == '/')
            {
                st.push(op1 / op2);
            }
        }
        else
        {
            int data = c - '0';
            st.push(data);
        }
    }
    return st.top();
}

int prec(char &c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string toPostFix(string &exp)
{
    stack<char> st;
    string result;

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
        {
            result = result + c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result = result + st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(c) <= prec(st.top()))
            {
                result = result + st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result = result + st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string exp = "(1+7)*(4-2)";
    string post = toPostFix(exp);
    cout << post << endl;
    int result = calculate(post);
    cout << result << endl;
    return 0;
}