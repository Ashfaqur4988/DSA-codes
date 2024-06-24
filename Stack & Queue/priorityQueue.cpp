#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(6);
    pq.push(-10);
    print(pq);
    return 0;
}