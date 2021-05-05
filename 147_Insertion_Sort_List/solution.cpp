#include "header.h"

ListNode* insertionSortList(ListNode* head)
{
    if (!head)
    {
        return head;
    }

    ListNode* new_head = head;
    head = head->next;
    new_head->next = nullptr;

    while (head)
    {
        ListNode* insert_pre = nullptr;
        ListNode* insert_pos = new_head;
        while (insert_pos)
        {
            if (insert_pos->val >= head->val)
            {
                break;
            }
            insert_pre = insert_pos;
            insert_pos = insert_pos->next;
        }

        if (insert_pre)
        {
            // Insert somewhere in between two nodes in the new list.
            insert_pre->next = head;
            head = head->next;
            insert_pre->next->next = insert_pos;
        }
        else
        {
            // Insert at the beginning of the new list.
            new_head = head;
            head = head->next;
            new_head->next = insert_pos;
        }
    }

    return new_head;
}