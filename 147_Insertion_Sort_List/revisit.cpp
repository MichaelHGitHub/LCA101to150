#include "header.h"

ListNode* insertionSortList_r(ListNode* head)
{
    ListNode dummy;
    dummy.next = head;

    if (nullptr != head)
    {
        ListNode* node = head->next;
        ListNode* pre = head;

        while (nullptr != node)
        {
            ListNode* insert_after = &dummy;

            while (insert_after != pre && insert_after->next->val <= node->val)
            {
                insert_after = insert_after->next;
            }

            if (insert_after != pre)
            {
                pre->next = node->next;

                node->next = insert_after->next;
                insert_after->next = node;

                node = pre->next;
            }
            else
            {
                pre = node;
                node = node->next;
            }
        }
    }

    return dummy.next;
}