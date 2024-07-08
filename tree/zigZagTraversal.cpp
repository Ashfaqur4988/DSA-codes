vector<vector<int>> ans;
if (root == NULL)
    return ans;

queue<TreeNode *> q;
bool flag = true;
q.push(root);
while (!q.empty())
{
    int size = q.size();
    vector<int> level(size);
    for (int i = 0; i < size; i++)
    {
        TreeNode *node = q.front();
        q.pop();
        int index = flag ? i : (size - 1 - i);

        level[index] = node->val;
        if (node->left)
        {
            q.push(node->left);
        }

        if (node->right)
        {
            q.push(node->right);
        }
    }
    flag = !flag;
    ans.push_back(level);
}
return ans;