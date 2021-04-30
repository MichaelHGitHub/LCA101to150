#include "header.h"

// Two runners: fast(2 steps at a time) and slow(1 step at a time).
// If there there is a loop, they will meet at some point eventially.
bool hasCycle2(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }
        
    struct ListNode* p;
    struct ListNode* q;
    p = q = head;
    while (p && q)
    {
        p = p->next;
        q = q->next;
        q = (q != NULL ? q->next : NULL);

        if (p == q)
        {
            return true;
        }
    }
    return false;
}