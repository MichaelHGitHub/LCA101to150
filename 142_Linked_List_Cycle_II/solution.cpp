#include "header.h"

// Assume the loop-list joins at node K, use two runner slution, the fast
// runner will catch the slow runner at a point, say m, sooner or later 
// as illustrated below:
//               0...K...m...N
//                   |___^___|

// Let fast runner run at a speed twice of slow runner's speed, by the time 
// the fast runner catches the slow runner, fast runner will cover a distance
// twice of what slow runner covers. In the illustration, the slow runner covers
// S(0-K + K-m), the fast runner covers a 2S(0-K + n*(K-m + m-N) + K-m), 
// therefore, S(0-k) = (n-1)*S(m-N + K-m) + S(m-N).
// So, once we've found point m, we let one point start at 0, another pointer start 
// m->next, the two pointer will eventually meet at K after the second pointer running 
// n-1 cycle plus S(m-N).
// Special case: if the the list joints at the head, no need to run the second round.

ListNode* detectCycle(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    bool srint = true;
    while (slow && fast)
    {
        slow = slow->next;
        fast = fast->next;

        if (srint)
        {
            fast = fast ? fast->next : nullptr;
        }

        if (slow == fast)
        {
            // if the the list joints at the head, no need to run the second round.
            if (fast == head)
            {
                return fast;
            }

            if (srint)
            {
                srint = false;
                fast = head;
            }
            else
            {
                return fast;
            }
        }
    }

    return nullptr;
}