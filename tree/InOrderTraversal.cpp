vector<int> inOrderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *node = root;
    vector<int> inOrder;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            inOrder.push_back(node->val);
            node = node->right;
        }
    }
    return inOrder;
}