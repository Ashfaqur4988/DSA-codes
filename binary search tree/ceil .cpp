int c = -1;
while (node)
{
    if (node->data == x)
    {
        c = node->data;
        return c;
    }
    if (node->data < x)
    {
        node = node->right;
    }
    else
    {
        c = node->data;
        node = node->left;
    }
}
return c;