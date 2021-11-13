#include "header.h"

static ListNode* mergeList(ListNode* head1, ListNode* head2);
static ListNode* splitList(ListNode* head);
static ListNode* sortList(ListNode* head);

ListNode* sortList_r2(ListNode* head)
{
    return sortList(head);
}

ListNode* sortList(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
    {
        return head;
    }

    ListNode* mid = splitList(head);

    ListNode* head1 = sortList(head);
    ListNode* head2 = sortList(mid);

    return mergeList(head1, head2);
}

ListNode* mergeList(ListNode* head1, ListNode* head2)
{
    ListNode dummy;
    ListNode* cur = &dummy;

    ListNode* node1 = head1;
    ListNode* node2 = head2;
    while (nullptr != node1 && nullptr != node2)
    {
        if (node1->val <= node2->val)
        {
            cur->next = node1;
            node1 = node1->next;
        }
        else
        {
            cur->next = node2;
            node2 = node2->next;
        }
        cur = cur->next;
    }

    while (nullptr != node1)
    {
        cur->next = node1;
        cur = cur->next;
        node1 = node1->next;
    }

    while (nullptr != node2)
    {
        cur->next = node2;
        cur = cur->next;
        node2 = node2->next;
    }

    cur->next = nullptr;

    return dummy.next;
}

ListNode* splitList(ListNode* head)
{
    if (nullptr == head || nullptr == head->next)
    {
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* pre_slow = nullptr;

    while (nullptr != fast)
    {
        pre_slow = slow;
        slow = slow->next;

        fast = fast->next;
        if (nullptr != fast)
        {
            fast = fast->next;
        }
    }

    if (nullptr != pre_slow)
    {
        pre_slow->next = nullptr;
    }
    return slow;
}