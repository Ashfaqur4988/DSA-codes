int f = -1;
while (root)
{
    if (root->val == X)
    {
        f = root->val;
        return f;
    }
    if (root->val < X)
    {
        f = root->val;
        root = root->right;
    }
    else
    {
        root = root->left;
    }
}
return f;
