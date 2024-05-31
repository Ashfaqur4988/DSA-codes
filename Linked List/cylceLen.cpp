int len(Node *i, Node *j)
{
    int cnt = 1;
    j = j->next;
    while (i != j)
    {
        cnt++;
        j = j->next;
    }
    return cnt;
}

int hasCycle(ListNode *head)
{
    ListNode *i = head;
    ListNode *j = head;

    while (j != NULL && j->next != NULL)
    {
        j = j->next->next;
        i = i->next;
        if (i == j)
        {
            return len(i, j);
        }
    }
    return 0;
}