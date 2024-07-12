TreeNode *curr = root;
if (root == NULL)
    return new TreeNode(val);
while (true)
{
    if (curr->val <= val)
    {
        if (curr->right != NULL)
            curr = curr->right;
        else
        {
            curr->right = new TreeNode(val);
            break;
        }
    }
    else
    {
        if (curr->left != NULL)
            curr = curr->left;
        else
        {
            curr->left = new TreeNode(val);
            break;
        }
    }
}
return root;