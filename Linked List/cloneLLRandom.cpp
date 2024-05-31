void insertCopyInBetween(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}

void connectRandom(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *copyNode = temp->next;
        if (temp->random)
        {
            copyNode->random = temp->random->next;
        }
        else
        {
            copyNode->random = NULL;
        }
        temp = temp->next->next;
    }
}

Node *getDeepCopy(Node *&head)
{
    Node *dummy = new Node(-1);
    Node *res = dummy;
    Node *temp = head;
    while (temp != NULL)
    {
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummy->next;
}

Node *copyRandomList(Node *head)
{
    insertCopyInBetween(head);
    connectRandom(head);
    return getDeepCopy(head);
}