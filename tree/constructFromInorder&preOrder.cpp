TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
}

TreeNode *build(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd, map<int, int> &mp)
{
    if (pStart > pEnd || iStart > iEnd)
        return NULL;

    TreeNode *node = new TreeNode(preorder[pStart]);
    int inNode = mp[node->val];
    int numsLeft = inNode - iStart;

    node->left = build(preorder, pStart + 1, pStart + numsLeft, inorder, iStart, inNode - 1, mp);
    node->right = build(preorder, pStart + numsLeft + 1, pEnd, inorder, inNode + 1, iEnd, mp);

    return node;
}