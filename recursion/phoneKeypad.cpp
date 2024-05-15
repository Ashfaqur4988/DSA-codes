#include <iostream>
#include <vector>
using namespace std;
void solveKeypad(string num, int i, string output, vector<string> &ans, string map[])
{
    // base case
    if (i >= num.length())
    {
        ans.push_back(output);
        return;
    }

    int digit = num[i] - '0';
    string val = map[digit];
    for (int j = 0; j < val.length(); j++)
    {
        output.push_back(val[j]);
        solveKeypad(num, i + 1, output, ans, map);
        output.pop_back();
    }
}
vector<string> keypad(string num)
{
    vector<string> ans;
    if (num.length() == 0)
    {
        return ans;
    }
    string output = "";
    int i = 0;
    string map[10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solveKeypad(num, i, output, ans, map);
    return ans;
}
int main()
{
    string num = "23";
    vector<string> ans = keypad(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}