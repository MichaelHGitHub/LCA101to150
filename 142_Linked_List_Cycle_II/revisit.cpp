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
ListNode* detectCycle_r(ListNode* head)
{
    ListNode* meet = nullptr;
    ListNode* connect = nullptr;

    if (nullptr != head)
    {
        ListNode* runner1 = head;
        ListNode* runner2 = head->next;

        while (nullptr != runner1 && nullptr != runner2 && runner1 != runner2)
        {
            runner1 = runner1->next;
            runner2 = runner2->next;

            if (nullptr != runner2)
            {
                runner2 = runner2->next;
            }
        }

        if (nullptr != runner1 && nullptr != runner2 && runner1 == runner2)
        {
            meet = runner1;
        }

        if (nullptr != meet)
        {
            runner1 = head;
            runner2 = meet->next;

            while (runner1 != runner2)
            {
                runner1 = runner1->next;
                runner2 = runner2->next;
            }

            connect = runner1;
        }
    }

    return connect;
}