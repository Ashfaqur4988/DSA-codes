vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    preOrder(root, 0, ans);
    return ans;
}

void preOrder(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->val);
    }
    preOrder(root->right, level + 1, ans);
    preOrder(root->left, level + 1, ans);
}