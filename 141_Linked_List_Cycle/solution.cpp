#include "header.h"

bool hasCycle(ListNode* head)
{
    ListNode* node = head;
    // The limit of node value is 10^5, we set a mark (10^5 + 1) to mark a 
    // node has been visited.
    int mark = 10001;

    while (node && node->val != mark)
    {
        node->val = mark;
        node = node->next;
    }

    if (node && node->val == mark)
    {
        return true;
    }
    else
    {
        return false;
    }
}