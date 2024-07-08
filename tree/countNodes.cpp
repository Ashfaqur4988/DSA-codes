int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = findLeftH(root);
    int rh = findRightH(root);

    // if both side same height
    if (lh == rh)
        return (1 << lh) - 1; // 2 to the power of lh
    // else if not same height
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findLeftH(TreeNode *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->left;
    }
    return h;
}

int findRightH(TreeNode *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->right;
    }
    return h;
}