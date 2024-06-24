#include <iostream>
#include <queue>
using namespace std;

void show(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    show(q);

    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    return 0;
}