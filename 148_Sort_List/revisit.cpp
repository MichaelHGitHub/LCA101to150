#include "header.h"

static void quickSortList(ListNode* pre, ListNode* post);
static ListNode* partitionList(ListNode* pre, ListNode* post);

ListNode* sortList_r(ListNode* head)
{
    ListNode dummy;
    dummy.next = head;
    quickSortList(&dummy, nullptr);
    return dummy.next;
}

void quickSortList(ListNode* pre, ListNode* post)
{
    if (nullptr == pre || pre == post || pre->next == post)
    {
        return;
    }

    ListNode* node = partitionList(pre, post);
    quickSortList(pre, node);
    quickSortList(node, post);
}

ListNode* partitionList(ListNode* pre, ListNode* post)
{
    if (nullptr == pre || pre == post || pre->next == post)
    {
        return nullptr;
    }

    ListNode* anchor = pre->next;
    ListNode* pre_cur = anchor;
    ListNode* cur = pre_cur->next;
    while (cur != post)
    {
        if (cur->val < anchor->val)
        {
            pre_cur->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = pre_cur->next;
        }
        else
        {
            pre_cur = cur;
            cur = cur->next;
        }
    }
    return anchor;
}