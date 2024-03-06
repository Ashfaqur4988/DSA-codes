#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> num)
{
    int count = 0;
    int n = num.size();

    for (int i = 1; i < n; i++)
    {
        if (num[i - 1] > num[i])
        {
            count++;
        }
    }
    if (num[n - 1] > num[0])
    {
        count++;
    }

    if (count <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> num;
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(1);
    num.push_back(2);

    for (auto i : num)
    {
        cout << i << " ";
    }
    cout << endl;

    if (check(num))
    {
        cout << "Yes!! rotated & sorted array";
    }
    else
    {
        cout << "No!! rotated & sorted array";
    }
    return 0;
}