bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    bool ans = false;
    inOrder(root, subRoot, ans);
    return ans;
}

bool match(TreeNode *root, TreeNode *subRoot)
{
    if (root != NULL && subRoot != NULL)
    {
        bool a = match(root->left, subRoot->left);
        bool b = match(root->right, subRoot->right);

        if (root->val == subRoot->val && a && b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    return false;
}

void inOrder(TreeNode *root, TreeNode *subRoot, bool &ans)
{
    if (root != NULL)
    {
        inOrder(root->left, subRoot, ans);

        bool x = match(root, subRoot);
        if (x)
        {
            ans = x;
        }

        inOrder(root->right, subRoot, ans);
    }
