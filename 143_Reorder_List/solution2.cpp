#include "header.h"

void reorderList2(ListNode* head)
{
    if (!head || !head->next || !head->next->next)
    {
        return;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* head2 = slow->next;
    slow->next = nullptr;

    ListNode* node = head2->next;
    ListNode* new_last = head2;
    while (node)
    {
        ListNode* next = node->next;
        node->next = head2;
        head2 = node;
        node = next;
    }
    new_last->next = nullptr;

    ListNode* l1 = head;
    ListNode* l2 = head2;
    while (l1 && l1->next && l2)
    {
        ListNode* next1 = l1->next;
        ListNode* next2 = l2->next;
        l1->next = l2;
        l2->next = next1;

        l1 = next1;
        l2 = next2;
    }
}