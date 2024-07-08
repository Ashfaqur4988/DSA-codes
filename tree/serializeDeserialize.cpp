string serialize(TreeNode *root)
{
    if (root == NULL)
        return "";

    queue<TreeNode *> q;
    string str = "";
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
        {
            str.append("#,");
        }
        else
        {
            str.append(to_string(node->val) + ",");
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << str;
    return str;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str != "#")
        {
            TreeNode *leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        else
        {

            node->left = NULL;
        }

        getline(s, str, ',');
        if (str != "#")
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
        else
        {
            node->right = NULL;
        }
    }
    return root;
}