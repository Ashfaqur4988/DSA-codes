vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> preOrder;
    if (root == NULL)
    {
        return preOrder;
    }
    stack<TreeNode *> st1;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        preOrder.push_back(root->val);
        if (root->left != NULL)
            st1.push(root->left);
        if (root->right != NULL)
            st1.push(root->right);
    }
    return preOrder;
}