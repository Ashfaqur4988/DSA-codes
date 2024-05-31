Node *hasCycle(ListNode *head)
{
    ListNode *i = head;
    ListNode *j = head;

    while (j != NULL && j->next != NULL)
    {
        j = j->next->next;
        i = i->next;
        if (i == j)
        {
            i = head;
            while (i != j)
            {
                i = i->next;
                j = j->next;
            }
            return i;
        }
    }
    return 0;
}