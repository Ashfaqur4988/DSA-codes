#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "top element " << s.top() << endl;
    s.pop();
    s.pop();
    cout << "top element " << s.top() << endl;
    if (s.empty())
    {
        cout << "stack empty" << endl;
    }
    else
    {
        cout << "stack not empty" << endl;
    }
    cout << "size of stack " << s.size() << endl;
    return 0;
}