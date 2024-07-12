TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return root;

    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

// approach 2

if (root == NULL || root == p || root == q)
    return root;

TreeNode *left = lowestCommonAncestor(root->right, p, q);

TreeNode *right = lowestCommonAncestor(root->left, p, q);

if (left == NULL)
{
    return right;
}
if (right == NULL)
{
    return left;
}
return root;