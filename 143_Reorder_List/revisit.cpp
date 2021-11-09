#include "header.h"

void reorderList_r(ListNode* head)
{
    vector<ListNode*> nodes;
    ListNode* cur = head;
    while (nullptr != cur)
    {
        nodes.push_back(cur);
        cur = cur->next;
    }

    int left = 0;
    int right = nodes.size() - 1;
    while (right - left > 1)
    {
        nodes[left]->next = nodes[right];
        nodes[right]->next = nodes[left + 1];
        ++left;
        --right;
    }
    if (right > 0)
    {
        nodes[right]->next = nullptr;
    }
}