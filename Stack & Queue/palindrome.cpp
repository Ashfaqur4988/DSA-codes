#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isPalindrome(vector<int> &arr)
{
    stack<int> s;
    int i = 0;
    int n = arr.size();
    for (i = 0; i < n / 2; i++)
    {
        s.push(arr[i]);
    }

    if (n % 2 != 0)
    {
        i++;
    }

    while (!s.empty())
    {
        if (s.top() != arr[i])
        {
            return false;
        }
        s.pop();
        i++;
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 4, 6, 2, 1};
    bool ans = isPalindrome(arr);
    if (ans)
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "not palindrome" << endl;
    }
    return 0;
}