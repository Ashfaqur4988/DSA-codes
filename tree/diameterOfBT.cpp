int findMax(TreeNode<int> *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lh = findMax(root->left, maxi);
    int rh = findMax(root->right, maxi);

    maxi = max(maxi, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int maxi = 0;

    findMax(root, maxi);

    return maxi;
}