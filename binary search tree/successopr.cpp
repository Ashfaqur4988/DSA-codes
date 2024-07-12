Node *s = NULL;

while (root != NULL)
{
    if (root->data <= x->data)
    {
        root = root->right;
    }
    else
    {
        s = root;
        root = root->left;
    }
}
return s;