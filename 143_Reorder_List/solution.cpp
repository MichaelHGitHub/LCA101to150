#include "header.h"

void reorderList(ListNode* head)
{
    vector<ListNode*> nodes;
    ListNode* node = head;
    while (node)
    {
        nodes.push_back(node);
        node = node->next;
    }

    if (nodes.size() > 2)
    {
        int left = 0;
        int right = nodes.size() - 1;
        while (right - left > 1)
        {
            nodes[left]->next = nodes[right];
            nodes[right]->next = nodes[left + 1];
            // We could set the end next to null each time or set it once
            // at the very end like it is done below
            //nodes[right - 1]->next = nullptr;
            ++left;
            --right;
        }
        nodes[right]->next = nullptr;
    }
}