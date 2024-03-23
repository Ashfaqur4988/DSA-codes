#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int> &ans)
{
    int start = 0;
    int end = ans.size() - 1;

    while (start <= end)
    {
        swap(ans[start], ans[end]);
        start++;
        end--;
    }
}

vector<int> sum(vector<int> v1, vector<int> v2, int m, int n)
{
    int i = m - 1;
    int j = n - 1;
    vector<int> ans;
    int carry = 0;
    // array equal size
    while (i >= 0 && j >= 0)
    {
        int val1 = v1[i];
        int val2 = v2[j];

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // first array is longer
    while (i >= 0)
    {
        int sum = v1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // second array is longer
    while (j >= 0)
    {
        int sum = v2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // carry is there
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    reverse(ans);
    return ans;
}

int main()
{
    vector<int> v1;
    vector<int> v2;

    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(1);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    cout << "array 1 : ";
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "array 2 : ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res = sum(v1, v2, 3, 3);

    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}