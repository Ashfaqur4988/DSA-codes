#include <iostream>
#include <vector>
using namespace std;
void solveKeyPad(string num, string output, vector<string> &ans, int i, string map[])
{
    if (i >= num.size())
    {
        ans.push_back(output);
        return;
    }

    int digit = num[i] - '0';
    string val = map[digit];
    for (int j = 0; j < val.length(); j++)
    {
        output.push_back(val[j]);
        solveKeyPad(num, output, ans, i + 1, map);
        output.pop_back();
    }
}
vector<string> keypad(string &num)
{
    vector<string> ans;
    if (num.size() == 0)
    {
        return ans;
    }

    string output = "";
    int i = 0;
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solveKeyPad(num, output, ans, i, map);
    return ans;
}
int main()
{
    string num = "36";
    vector<string> ans = keypad(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}