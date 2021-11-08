#include "header.h"

bool hasCycle_r(ListNode* head)
{
    bool result = false;

    if (nullptr != head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (nullptr != fast && nullptr != slow && fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
            if (nullptr != fast)
            {
                fast = fast->next;
            }
        }

        if (nullptr != fast && nullptr != slow && fast == slow)
        {
            result = true;
        }
    }

    return result;
}