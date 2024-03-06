#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> num, int k)
{
    vector<int> temp(num.size());
    for (int i = 0; i < num.size(); i++)
    {
        temp[(i + k) % num.size()] = num[i];
    }
    num = temp;
    for (auto i : num)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int steps = 3;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);

    cout << "before" << endl;
    for (auto i : num)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "after " << endl;
    rotate(num, steps);
    return 0;
}