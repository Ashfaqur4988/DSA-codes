bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if ((root->left == NULL && root->right == NULL))
        return true;

    return isValid(root, INT_MIN, INT_MAX);
}

bool isValid(TreeNode *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->val >= max || root->val <= min)
    {
        return false;
    }
    bool left = isValid(root->left, min, root->val);
    bool right = isValid(root->right, root->val, max);
    return left && right;
}