int kthSmallest(TreeNode *root, int k)
{
    int cnt = 0;
    int kth = INT_MAX;
    inorder(root, cnt, kth, k);
    return kth;
}

void inorder(TreeNode *&root, int &cnt, int &kth, int &k)
{
    if (!root || cnt >= k)
    {
        return;
    }
    inorder(root->left, cnt, kth, k);
    cnt++;
    if (cnt == k)
    {
        kth = root->val;
        return;
    }
    inorder(root->right, cnt, kth, k);
}

// reverse the inorder left and right to get the largest;