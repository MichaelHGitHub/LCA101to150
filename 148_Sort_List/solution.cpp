#include "header.h"

ListNode* divideList(ListNode* l);
ListNode* mergeList(ListNode* l1, ListNode * l2);

ListNode* sortList(ListNode* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    ListNode* head2 = divideList(head);

    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(head2);

    return mergeList(l1, l2);
}

ListNode* divideList(ListNode* l)
{
    if (!l || !l->next)
    {
        return l;
    }

    ListNode* fast = l;
    ListNode* slow = l;

    while (fast && fast->next)
    {
        fast = fast->next;
        fast = fast ? fast->next : nullptr;

        // If fast reaches end->next, slow doesn't need to move anymore.
        if (fast)
        {
            slow = slow->next;
        }
    }
    // Second list starts from slow->next.
    ListNode* head = slow->next;
    slow->next = nullptr;

    return head;
}

ListNode* mergeList(ListNode* l1, ListNode* l2)
{
    ListNode dummy = ListNode();
    ListNode* node = &dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }

        node = node->next;
    }

    while (l1)
    {
        node->next = l1;
        l1 = l1->next;
        node = node->next;
    }

    while (l2)
    {
        node->next = l2;
        l2 = l2->next;
        node = node->next;
    }
    node->next = nullptr;

    return dummy.next;
}