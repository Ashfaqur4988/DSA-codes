#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v, int index)
{
    int s = index;
    int e = v.size() - 1;

    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

int main()
{
    int index = 3;
    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    cout << "before" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ans = reverse(v, index);
    cout << "after " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}